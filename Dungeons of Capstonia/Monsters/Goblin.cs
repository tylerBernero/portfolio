﻿using Capstonia.Core;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using System;
using Rectangle = RogueSharp.Rectangle;

namespace Capstonia.Monsters
{
    public class Goblin : Monster
    {
        int oldPlayerX;
        int oldPlayerY;
        // constructor
        public Goblin(GameManager game) : base(game)
        {
            Level = 2;
            // every point above 10 gives a health bonus
            Constitution = 10;
            // every point above 10 gives a dodge bonus
            Dexterity = 10;
            // health total for Capstonian; if the values reaches 0, the Capstonain is killed
            MaxHealth = 10;
            // current health for Capstonian; if the values reaches 0, the Capstonain is killed
            CurrHealth = 10;
            // max dmg Capstonian can cause
            MaxDamage = 5;
            // min dmg Capstonain can cause
            MinDamage = 2;
            // name of monster
            Name = "Goblin";
            // every point above 10 gives a dmg bonus
            Strength = 10;
            //Level = 2;
            MinGlory = 3;
            MaxGlory = 5;
            Sprite = game.goblin;
            oldPlayerX = game.Player.X;
            oldPlayerY = game.Player.Y;
            
        }
    }
}