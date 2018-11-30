﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using Capstonia.Core;
using System.Diagnostics;

namespace Capstonia.Systems
{
    public class Credits
    {
        private GameManager game;
        private List<string> CreditMessages;
        TimeSpan gameTime;

        public Credits(GameManager game)
        {
            this.game = game;
            CreditMessages = new List<string>();

            CreditMessages.Add("Produced and Developed By: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Tommy McDermott" + Environment.NewLine +
                                "Chido Nguyen" + Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Random Level Generation: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Message Log Creation: " + Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Random Level Generation: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Actor/Player/Monster Creation and UI: " + Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Item Creation: " + Environment.NewLine + "Tyler Bernero" + 
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Item and Enemy Spawning: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Inventory System and UI" + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Combat System: " + Environment.NewLine + "Tommy McDermott" +
                                Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Monster AI: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Item Creation: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Nearby Monster AI: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Equipment System: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Experience and Level System " + Environment.NewLine + "Tommy McDermott" +
                                Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Hunger System: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Chido Nguyen");
            CreditMessages.Add("Main Menu: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Leaderboards: " + Environment.NewLine + "Tommy McDermott" +
                                Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Sound/SFX: " + Environment.NewLine + "Tommy McDermott");
            CreditMessages.Add("Testing: " + Environment.NewLine + "Tyler Bernero" +
                                Environment.NewLine + "Tommy McDermott" + Environment.NewLine +
                                "Chido Nguyen" + Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Balance/Tweaking: " + Environment.NewLine + "Tyler Bernero" +
                               Environment.NewLine + "Tommy McDermott" + Environment.NewLine +
                               "Chido Nguyen" + Environment.NewLine + "Bobby Welch");
            CreditMessages.Add("Press <SPACE> to go to the Main Menu");
        }

        public void Update()
        {
            // get current keyboard state
            game.currentKeyboardState = Keyboard.GetState();

            if (game.currentKeyboardState.IsKeyUp(Keys.Space) && game.previousKeyboardState.IsKeyDown(Keys.Space))
            {
                game.MenuDown.Play();
                game.state = GameState.MainMenu;
            }


            // save current state to previous and get ready for next move
            game.previousKeyboardState = game.currentKeyboardState;

        }


        public void Draw(SpriteBatch spriteBatch)
        {
            //Stopwatch source; https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.stopwatch.startnew?view=netframework-4.7.2
            int xOffset = 50;
            int yOffset = 50;

            //Set vectors to draw sprites in the corners of the screen
            Vector2 topLeft = new Vector2(0, 0);
            Vector2 topRight = new Vector2(game.graphics.PreferredBackBufferWidth - 48, 0);
            Vector2 bottomLeft = new Vector2(0, game.graphics.PreferredBackBufferHeight - 48);
            Vector2 bottomRight = new Vector2(game.graphics.PreferredBackBufferWidth - 48, game.graphics.PreferredBackBufferHeight - 48);

            //Place sprites of the player in the corners of the screen
            spriteBatch.Draw(game.Player.Sprite, topLeft, Color.White);
            spriteBatch.Draw(game.Player.Sprite, topRight, Color.White);
            spriteBatch.Draw(game.Player.Sprite, bottomLeft, Color.White);
            spriteBatch.Draw(game.Player.Sprite, bottomRight, Color.White);

            Stopwatch elapsedTime = new Stopwatch();
            
            foreach (string message in CreditMessages)
            {
                game.GraphicsDevice.Clear(Color.Black);
                spriteBatch.DrawString(game.mainFont, message, new Vector2(xOffset, yOffset), Color.White);
                yOffset += 115;

                if(yOffset >= 800)
                {
                    xOffset += 333;
                    yOffset = 50;
                }
                //elapsedTime.Reset();
                //elapsedTime.Start();

                //Wait 2 seconds before displaying the next credit
                //while (elapsedTime.ElapsedMilliseconds <= 2000)
                //{
                    //Do nothing
                //}
            }
        }
    }
}
