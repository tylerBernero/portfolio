﻿using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using RogueSharp;
using RogueSharp.Random;
using System;
using System.Collections.Generic;
using Capstonia.Systems;
using Capstonia.Core;
using Capstonia.Items;
using Rectangle = Microsoft.Xna.Framework.Rectangle;
using Microsoft.Xna.Framework.Audio;

namespace Capstonia
{
    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class GameManager : Game
    {
        // GameState Controller (Scene Control)
        // based on: http://community.monogame.net/t/switch-scenes-in-monogame/2605
        public GameState state;
        public MainMenu MainMenu { get; set; }
        public PlayerCreation PlayerCreation { get; set; }
        public Instructions Instructions { get; set; }
        public Leaderboard Leaderboard { get; set; }
        public Credits Credits { get; set; }
        public Confirmation Confirmation {get; set;}


        // Game Variable Declarations
        public readonly int levelWidth = 70;
        public readonly int levelHeight = 70;
        public readonly int levelRows = 5;
        public readonly int levelCols = 5;
        public readonly int maxLevel = 10;
        public int mapLevel = 1;
        public readonly int tileSize = 48;
        public float scale = 1.0f;

        // Game Actor Constants
        public readonly int BaseStrength = 10;
        public readonly int BaseDexterity = 10;
        public readonly int BaseConstitution = 10;

        // used for game resetting checks
        public bool PlayerWin = false;
        public bool PlayerDead = false;


        // RogueSharp Specific Declarations
        public static IRandom Random { get; private set; }
        public Player Player { get; set; }
        public MapLevel MapLevelDisplay { get; set; }
        public Monster Monster { get; set; }
        public LevelGrid Level { get; private set; }
        public MessageLog Messages { get; set; }
        public Score ScoreDisplay { get; set; }
        public CommandSystem CommandSystem;
        public PathFinder GlobalPositionSystem;

        // MonoGame Specific Declarations
        public GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        public Texture2D floor;
        public Texture2D wall;
        public Texture2D exit;
        public SpriteFont mainFont;
        public SpriteFont pressStart2PFont;
        public SpriteFont pressStart2PSmallFont;

        // Items - Gameboard
        // Armor
        public Texture2D armor;
        public Texture2D armor_leather_chest;
        public Texture2D armor_steel_chest;
        public Texture2D armor_gold_chest;
        public Texture2D armor_emerald_chest;
        public Texture2D armor_diamond_chest;
        public Texture2D armor_blood_chest;
            //Food
        public Texture2D food;
            //Weapon
        public Texture2D weapon_club;
        public Texture2D weapon_axe_gold;
        public Texture2D weapon_lance_vorpal;
        public Texture2D weapon_sword_acid;
        public Texture2D weapon_sword_diamond;
        public Texture2D weapon_sword_hellfire;
        public Texture2D weapon_sword_lightning;
            //Potion
        public Texture2D potion;
            //Book
        public Texture2D book;
        public Texture2D bookStr;
        public Texture2D BookDex;
        public Texture2D BookCst;
        public Texture2D BookBad;
            //Gem
        public Texture2D gem;
            //Chest
        public Texture2D chest;

        // Items - Player Stats
        public Texture2D constitution;
        public Texture2D dexterity;
        public Texture2D experience;
        public Texture2D health;
        public Texture2D level;
        public Texture2D strength;

        // Monsters
        public Texture2D banshee;
        public Texture2D barbarian;
        public Texture2D bat;
        public Texture2D beholder;
        public Texture2D demon;
        public Texture2D dragon;
        public Texture2D drowelf;
        public Texture2D fireelemental;
        public Texture2D goblin;
        public Texture2D lich;
        public Texture2D lizardman;
        public Texture2D minotaur;
        public Texture2D mummy;
        public Texture2D ogre;
        public Texture2D rat;
        public Texture2D skeleton;
        public Texture2D slime;
        public Texture2D snake;
        public Texture2D spider;
        public Texture2D spirit;
        public Texture2D stonegolem;
        public Texture2D troll;
        public Texture2D valkyrie;
        public Texture2D vampire;
        public Texture2D wolf;
        public Texture2D wraith;
        public Texture2D zombie;

        // main menu graphic
        public Texture2D mainMenuGraphic;

        // new player graphic
        public Texture2D darkKnightLarge;

        // music
        public SoundEffect menuSong;
        public SoundEffectInstance menuMusic;

        public SoundEffect gameSong;
        public SoundEffectInstance gameMusic;


        // sfx
        public SoundEffect BlockAttack;
        //public SoundEffectInstance BlockInst;
        public SoundEffect DodgeAttack;
        //public SoundEffectInstance DodgeInst;
        public SoundEffect MonsterDeath;
        //public SoundEffectInstance MonsterDeathInst;
        public List<SoundEffect> MonsterHit;
        public List<SoundEffect> PlayerHit;
        public SoundEffect BookSound;
        public SoundEffect EatingSound;
        public SoundEffect DrinkingSound;
        public List<SoundEffect> Footsteps;
        public SoundEffect GameOver;
        public SoundEffect PlayerDeath;
        public SoundEffect ItemPickup;
        public SoundEffect LevelUp;
        public SoundEffect MenuDown;
        public SoundEffect MenuUp;
        public SoundEffect ArmorSound;
        public SoundEffect WeaponSound;

        

        // containers
        public List<Monster> Monsters;
        public List<Item> Items;
        
        //Inventory
        public InventorySystem Inventory;
        public Rectangle inventoryScreen;
        public Texture2D emptyTexture; //used to fill a blank rectangle (i.e., inventoryScreen)
        public Texture2D Outline;

        //Equipment
        public Equipment Equip;
        
        // Player Stats and Equipment
        public Texture2D PlayerStatsOutline;
        public Texture2D PlayerEquipmentOutline;

        // Monster Stats
        public Texture2D MonsterStatsOutline;

        // track keyboard state (i.e. capture key presses)
        public KeyboardState currentKeyboardState;
        public KeyboardState previousKeyboardState;

        public GameManager() : base()
        {
            state = GameState.MainMenu;

            // Scenes other than GameManager itself
            MainMenu = new MainMenu(this);
            PlayerCreation = new PlayerCreation(this);
            Instructions = new Instructions(this);
            Leaderboard = new Leaderboard(this);
            Credits = new Credits(this);
            Confirmation = new Confirmation(this);

            // MonoGame Graphic/Content setup
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferWidth = 1000;
            graphics.PreferredBackBufferHeight = 858;
            Content.RootDirectory = "Content";

            // add player instance
            Player = new Player(this);

            // add monster instance
            Monster = new Monster(this);

            //link the messageLog and game instance
            Messages = new MessageLog(this);

            // display glory/score
            ScoreDisplay = new Score(this);

            // display map level player is on
            MapLevelDisplay = new MapLevel(this);

            // Player provided commands
            CommandSystem = new CommandSystem(this);

            //Create Inventory for player
            Inventory = new InventorySystem(this);
            inventoryScreen = new Rectangle(200, 100, 1200, 0);   //Height, Width, X, Y

            //Equipment
            Equip = new Equipment(this);

        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // initialize lists
            Monsters = new List<Monster>();
            Items = new List<Item>();

            // get seed based on current time and set up RogueSharp Random instance
            int seed = (int)DateTime.UtcNow.Ticks;
            Random = new DotNetRandom(seed);

            // initialize soundeffect lists
            MonsterHit = new List<SoundEffect>();
            PlayerHit = new List<SoundEffect>();
            Footsteps = new List<SoundEffect>();

            //https://stackoverflow.com/questions/22535699/mouse-cursor-is-not-showing-in-windows-store-game-developing-using-monogame
            this.IsMouseVisible = true;

            base.Initialize();
        }


        // Reinitialize()
        // DESC:        Initializes game back to starting state
        // PARAMS:      None
        // RETURNS:     None
        public void Reinitialize()
        {
            PlayerDead = false;
            PlayerWin = false;

            Monsters.Clear();
            Items.Clear();
            mapLevel = 1;

            Player = new Player(this);
            Player.Sprite = Content.Load<Texture2D>("Art/Sprites/dknight_1");
            Messages = new MessageLog(this);
            Inventory = new InventorySystem(this);
            Equip = new Equipment(this);

            GenerateLevel();

        }


        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // load level textures
            floor = Content.Load<Texture2D>("Art/Sprites/floor_extra_12");
            wall = Content.Load<Texture2D>("Art/Sprites/wall_stone_11");
            exit = Content.Load<Texture2D>("Art/Sprites/floor_set_grey_8");

            // load item textures - gameboard

            //chest
            chest = Content.Load<Texture2D>("Art/Sprites/chest_gold_open");
            //armor
            armor = Content.Load<Texture2D>("Art/Sprites/armor");
            armor_leather_chest = Content.Load<Texture2D>("Art/Sprites/armor_leather_chest");
            armor_steel_chest = Content.Load<Texture2D>("Art/Sprites/armor_steel_chest");
            armor_gold_chest = Content.Load<Texture2D>("Art/Sprites/armor_gold_chest");
            armor_emerald_chest = Content.Load<Texture2D>("Art/Sprites/armor_emerald_chest");
            armor_diamond_chest = Content.Load<Texture2D>("Art/Sprites/armor_diamond_chest");
            armor_blood_chest = Content.Load<Texture2D>("Art/Sprites/armor_blood_chest");
            //food
            food = Content.Load<Texture2D>("Art/Sprites/drumstick");
            //weapon
            weapon_club = Content.Load<Texture2D>("Art/Sprites/weapon_club");
            weapon_axe_gold = Content.Load<Texture2D>("Art/Sprites/weapon_axe_gold");
            weapon_lance_vorpal = Content.Load<Texture2D>("Art/Sprites/weapon_lance_vorpal");
            weapon_sword_acid = Content.Load<Texture2D>("Art/Sprites/weapon_sword_acid");
            weapon_sword_diamond = Content.Load<Texture2D>("Art/Sprites/weapon_sword_diamond");
            weapon_sword_hellfire = Content.Load<Texture2D>("Art/Sprites/weapon_sword_hellfire");
            weapon_sword_lightning = Content.Load<Texture2D>("Art/Sprites/weapon_sword_lightning");
            //potions
            potion = Content.Load<Texture2D>("Art/Sprites/potion");
            //books
            book = Content.Load<Texture2D>("Art/Sprites/book");
            bookStr = Content.Load<Texture2D>("Art/Sprites/book_strength");
            BookDex = Content.Load<Texture2D>("Art/Sprites/book_dexterity");
            BookCst = Content.Load<Texture2D>("Art/Sprites/book_constitution");
            BookBad = Content.Load<Texture2D>("Art/Sprites/book_evil");
            //chest
            chest = Content.Load<Texture2D>("Art/Sprites/chest_gold_open");

            // load item textures - player stats
            constitution = Content.Load<Texture2D>("Art/Sprites/constitution");
            dexterity = Content.Load<Texture2D>("Art/Sprites/dexterity");
            experience = Content.Load<Texture2D>("Art/Sprites/experience");
            health = Content.Load<Texture2D>("Art/Sprites/health");
            level = Content.Load<Texture2D>("Art/Sprites/level");
            strength = Content.Load<Texture2D>("Art/Sprites/strength");

            // load gui textures
            Outline = Content.Load<Texture2D>("Art/UI/inventory_gui");
            PlayerStatsOutline = Content.Load<Texture2D>("Art/UI/player_stats_gui");
            PlayerEquipmentOutline = Content.Load<Texture2D>("Art/UI/player_equipment_gui");
            MonsterStatsOutline = Content.Load<Texture2D>("Art/UI/monster_stats_gui");

            // load actor textures
            Player.Sprite = Content.Load<Texture2D>("Art/Sprites/dknight_1");
            beholder = Content.Load<Texture2D>("Art/Sprites/beholder_deep_1");
            banshee = Content.Load<Texture2D>("Art/Sprites/banshee_1");
            barbarian = Content.Load<Texture2D>("Art/Sprites/barbarian_f_1");
            bat = Content.Load<Texture2D>("Art/Sprites/bat_giant_1");
            demon = Content.Load<Texture2D>("Art/Sprites/demon_red_1");
            dragon = Content.Load<Texture2D>("Art/Sprites/dragon_green_1");
            drowelf = Content.Load<Texture2D>("Art/Sprites/drow_1");
            fireelemental = Content.Load<Texture2D>("Art/Sprites/elemental_fire_1");
            goblin = Content.Load<Texture2D>("Art/Sprites/goblin_1");
            stonegolem = Content.Load<Texture2D>("Art/Sprites/golem_stone_1");
            lich = Content.Load<Texture2D>("Art/Sprites/lich_1");
            lizardman = Content.Load<Texture2D>("Art/Sprites/lizardman_blue_1");
            minotaur = Content.Load<Texture2D>("Art/Sprites/minotaur_1");
            mummy = Content.Load<Texture2D>("Art/Sprites/mummy_1");
            ogre = Content.Load<Texture2D>("Art/Sprites/ogre_1");
            rat = Content.Load<Texture2D>("Art/Sprites/rat_giant_1");
            skeleton = Content.Load<Texture2D>("Art/Sprites/skeleton_1");
            slime = Content.Load<Texture2D>("Art/Sprites/slime_purple_1");
            snake = Content.Load<Texture2D>("Art/Sprites/snake_giant_1");
            spider = Content.Load<Texture2D>("Art/Sprites/spider_black_giant_1");
            spirit = Content.Load<Texture2D>("Art/Sprites/spirit_1");
            troll = Content.Load<Texture2D>("Art/Sprites/troll_1");
            valkyrie = Content.Load<Texture2D>("Art/Sprites/valkyrie_b_1");
            vampire = Content.Load<Texture2D>("Art/Sprites/vampire_lord_1");
            wolf = Content.Load<Texture2D>("Art/Sprites/wolf_black_1");
            wraith = Content.Load<Texture2D>("Art/Sprites/wraith_a_1");
            zombie = Content.Load<Texture2D>("Art/Sprites/zombie_a_1");

            // load main menu graphic
            mainMenuGraphic = Content.Load<Texture2D>("Art/UI/main-menu");

            // load new player graphic
            darkKnightLarge = Content.Load<Texture2D>("Art/UI/dark-knight-large");

            // load music
            menuSong = Content.Load<SoundEffect>("Sounds/Music/MS-Melancholy Ambience");
            menuMusic = menuSong.CreateInstance();

            gameSong = Content.Load<SoundEffect>("Sounds/Music/MS-PrettyDungeon");
            gameMusic = gameSong.CreateInstance();

            // load sfx
            BlockAttack = Content.Load<SoundEffect>("Sounds/SFX/BlockAttack");
            BookSound = Content.Load<SoundEffect>("Sounds/SFX/BookSound");
            DodgeAttack = Content.Load<SoundEffect>("Sounds/SFX/DodgeAttack");
            EatingSound = Content.Load<SoundEffect>("Sounds/SFX/EatingSound");
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep1"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep2"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep3"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep4"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep5"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep6"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep7"));
            Footsteps.Add(Content.Load<SoundEffect>("Sounds/SFX/Footstep8"));
            GameOver = Content.Load<SoundEffect>("Sounds/SFX/GameOverVoice");
            ItemPickup = Content.Load<SoundEffect>("Sounds/SFX/ItemPickup");
            LevelUp = Content.Load<SoundEffect>("Sounds/SFX/LevelUp");
            MenuDown = Content.Load<SoundEffect>("Sounds/SFX/MenuDown");
            MenuUp = Content.Load<SoundEffect>("Sounds/SFX/MenuUp");
            MonsterDeath = Content.Load<SoundEffect>("Sounds/SFX/MonsterDeath");
            PlayerDeath = Content.Load<SoundEffect>("Sounds/SFX/PlayerDeathPiano");
            DrinkingSound = Content.Load<SoundEffect>("Sounds/SFX/PotionDrinking");
            MonsterHit.Add(Content.Load<SoundEffect>("Sounds/SFX/MonsterHit1"));
            MonsterHit.Add(Content.Load<SoundEffect>("Sounds/SFX/MonsterHit2"));
            MonsterHit.Add(Content.Load<SoundEffect>("Sounds/SFX/MonsterHit3"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit1"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit2"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit3"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit4"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit5"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit6"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit7"));
            PlayerHit.Add(Content.Load<SoundEffect>("Sounds/SFX/PlayerHit8"));
            ArmorSound = Content.Load<SoundEffect>("Sounds/SFX/ArmorSound");
            WeaponSound = Content.Load<SoundEffect>("Sounds/SFX/WeaponSound");


            // load fonts
            mainFont = Content.Load<SpriteFont>("Fonts/MainFont");
            pressStart2PFont = Content.Load<SpriteFont>("Fonts/PressStart2P");
            pressStart2PSmallFont = Content.Load<SpriteFont>("Fonts/PressStart2PSMall");

            //Drawing black screen for inventory inspired by: https://stackoverflow.com/questions/5751732/draw-rectangle-in-xna-using-spritebatch
            emptyTexture = new Texture2D(GraphicsDevice, 1, 1);
            emptyTexture.SetData(new[] { Color.White });

            GenerateLevel();

        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            switch (state)
            {
                case GameState.MainMenu:
                    gameMusic.Stop();                   
                    menuMusic.IsLooped = true;
                    menuMusic.Volume = 0.5f;
                    menuMusic.Play();
                    MainMenu.Update();
                    break;
                case GameState.PlayerCreation:
                    PlayerCreation.Update();
                    break;
                case GameState.Instructions:
                    Instructions.Update();
                    break;
                case GameState.Leaderboard:
                    Leaderboard.Update();
                    break;
                case GameState.Credits:
                    Credits.Update();
                    break;
                case GameState.Confirmation:
                    Confirmation.Update();
                    break;
                case GameState.GamePlay:
                    menuMusic.Stop();
                    gameMusic.Volume = 0.5f;
                    gameMusic.IsLooped = true;
                    gameMusic.Play();
                    UpdateGamePlay();
                    break;
            }

            base.Update(gameTime);
        }


        /// <summary>
        /// This is the GamePlay Update Controller
        /// </summary>
        protected void UpdateGamePlay()
        {
            //testing hunger timings//
            bool turnComplete = false;
            bool playerHasMoved = false;
            bool monstersHaveMoved = false;

            if (Player.CurrHealth > 0 && !PlayerWin)
            {
                while (turnComplete == false)
                {
                    // Handle keyboard input
                    if (Keyboard.GetState().IsKeyDown(Keys.Escape))
                    {
                        state = GameState.Confirmation;
                    }


                    // move player
                    if (playerHasMoved == false)
                    {
                        Player.Move();
                    }
                    playerHasMoved = true;

                    if (playerHasMoved)
                    {
                        //move Monsters
                        foreach (Monster enemy in Monsters)
                        {
                            enemy.Move();
                        }
                        monstersHaveMoved = true;
                    }

                    if (playerHasMoved && monstersHaveMoved)
                    {
                        turnComplete = true;
                    }
                }
            }
            else
            {
                if (Keyboard.GetState().IsKeyDown(Keys.Escape))
                {
                    state = GameState.Leaderboard;
                }
            }
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);

            // making the spriteBatch.begin(...) change below should fix the
            // rendering issues where layers would randomly render out of order
            // spriteBatch.Begin(SpriteSortMode.BackToFront, BlendState.AlphaBlend);
            spriteBatch.Begin();

            switch (state)
            {
                case GameState.MainMenu:
                    MainMenu.Draw(spriteBatch);
                    break;
                case GameState.PlayerCreation:
                    PlayerCreation.Draw(spriteBatch);
                    break;
                case GameState.Instructions:
                    Instructions.Draw(spriteBatch);
                    break;
                case GameState.Leaderboard:
                    Leaderboard.Draw(spriteBatch);
                    break;
                case GameState.Credits:
                    Credits.Draw(spriteBatch);
                    break;
                case GameState.Confirmation:
                    Confirmation.Draw(spriteBatch);
                    break;
                case GameState.GamePlay:
                    DrawGamePlay(spriteBatch);
                    break;
            }

            spriteBatch.End();

            base.Draw(gameTime);
        }

        /// <summary>
        /// Draw method for GamePlay
        /// </summary>
        protected void DrawGamePlay(SpriteBatch spriteBatch)
        {
            Inventory.Draw(spriteBatch);
            Messages.Draw(spriteBatch);
            ScoreDisplay.Draw(spriteBatch);
            MapLevelDisplay.Draw(spriteBatch);
            Level.Draw(spriteBatch);

            // draw all of the monsters in the list
            foreach (var monster in Monsters)
            {
                monster.Draw(spriteBatch);
            }

            // draw all of the items in the list
            foreach (var item in Items)
            {
                item.Draw(spriteBatch);
            }

            // draw player sprite
            Player.Draw(spriteBatch);

            // draw stats grid for player
            Player.DrawStats(spriteBatch);

            // draw stats grid for monsters
            Monster.DrawStats(spriteBatch);

            // draw equipment grid for player
            Player.DrawEquipment(spriteBatch);
        }

        // GenerateLevel()
        // DESC:    Generates the entire level grid in which individual rooms will be placed.     
        // PARAMS:  None.
        // RETURNS: None.
        public void GenerateLevel()
        {
            LevelGenerator levelGenerator = new LevelGenerator(this, levelWidth, levelHeight, levelRows, levelCols, mapLevel);
            Level = levelGenerator.CreateLevel();
        }

        // SetLevelCell()
        // DESC:    Takes data from object and passed data to UserInterface for level update
        // PARAMS:  x(int), y(int), type(ObjectType), isExplored(bool)
        // RETURNS: None.
        public void SetLevelCell(int x, int y, ObjectType type, bool isExplored)
        {
            //masterConsole.UpdateLevelCell(x, y, type, isExplored);
        }

        // IsInRoomWithPlayer()
        // DESC:    Determines if coordinates are in the same room as the player
        // PARAMS:  x(int), y(int)
        // RETURNS: Boolean (true if in same room, false otherwise)
        public bool IsInRoomWithPlayer(int x, int y)
        {
            // get room player is in
            int RoomIndex;
            for (RoomIndex = 0; RoomIndex < Level.Rooms.Count; RoomIndex++)
            {
                if(Player.X >= Level.Rooms[RoomIndex].Left && Player.X <= Level.Rooms[RoomIndex].Right && Player.Y >= Level.Rooms[RoomIndex].Top && Player.Y <= Level.Rooms[RoomIndex].Bottom)
                {
                    // found player room, now check if passed in coordinates exist within it
                    if(x >= Level.Rooms[RoomIndex].Left && x <= Level.Rooms[RoomIndex].Right && y >= Level.Rooms[RoomIndex].Top && y <= Level.Rooms[RoomIndex].Bottom)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            // player should always be located in the list of Rooms so we should never reach this point
            return false;
        }

        // HandleDeath()
        // DESC:    Handle monster death
        // PARAMS:  Monster
        // RETURNS: None
        public void HandleMonsterDeath(Monster monster)
        {
            MonsterDeath.Play();
            int addGlory = Random.Next(monster.MinGlory, monster.MaxGlory);
            Player.Glory += addGlory;

            int addExperience = monster.GetMonsterExperience();
            Player.Experience += addExperience;

            Messages.AddMessage("You have slaughtered the " + monster.Name + "!!!");            
            Messages.AddMessage("You have earned " + addGlory + " Glory worth of gold and bones!!!");
            Messages.AddMessage("You gained " + addExperience + " Experience Points!!!");

            Player.CheckLevelUp();
            
            Level.SetIsWalkable(monster.X, monster.Y, true);
            //10% drop//
            int rng = Capstonia.GameManager.Random.Next(1, 100);
            if (rng >= 90)
            {
                DropItemOnDeath(monster.X, monster.Y);
            }
            Monsters.Remove(monster);
        }

        // HandlePlayerDeath()
        // DESC:    Handle player death
        // PARAMS:  None
        // RETURNS: None
        public void HandlePlayerDeath(string monster)
        {
            PlayerDead = true;

            gameMusic.Stop();
            PlayerDeath.Play();
            Messages.AddMessage("You have DIED!  Game Over!");
            Messages.AddMessage("Press <ESC> to Exit Game.");

            DateTime today = DateTime.Now;

            string date = today.Month + "/" + today.Day + "/" + today.Year;

            Leaderboard.AddToLeaderboard(Player.Name, Player.Glory, mapLevel, monster, date);

            

        }

        // CheckPlayerWin()
        // DESC:    Checks if the player has found the treasure chest.  Ends game if so.
        // PARAMS:  x and y location of treasure chest
        // RETURNS: None
        public void PlayerWinCondition()
        {
            PlayerWin = true;

            Player.Glory += 100;

            gameMusic.Stop();

            Messages.AddMessage("You found the lost treasure!!!! You Win!!!!");
            Messages.AddMessage("Press <ESC> to Exit Game.");

            DateTime today = DateTime.Now;

            string date = today.Month + "/" + today.Day + "/" + today.Year;

            Leaderboard.AddToLeaderboard(Player.Name, Player.Glory, mapLevel, null, date);
        }

        // PlayRandomFromList()
        // DESC:    Play random sound from list passed in
        // PARAMS:  List of sounds
        // RETURNS: None
        public void PlayRandomFromList(List<SoundEffect> list)
        {
            list[Random.Next(0, list.Count - 1)].Play();
        }

        private void DropItemOnDeath(int x, int y)
        {
            ItemType itemIndex;
            Item item = null;

            itemIndex = (ItemType)GameManager.Random.Next(0,1);

            switch (itemIndex)
            {
                case ItemType.Potion:
                    item = new Potion(this);
                    break;
                case ItemType.Food:
                    item = new Food(this);
                    break;
            }

            item.X = x;
            item.Y = y;
            Level.AddItem(item);
        }
    }
}
