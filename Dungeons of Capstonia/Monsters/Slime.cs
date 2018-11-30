﻿using Capstonia.Core;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using System;
using Rectangle = RogueSharp.Rectangle;

namespace Capstonia.Monsters
{
    public class Slime : Monster
    {
        int oldPlayerX;
        int oldPlayerY;
        // constructor
        public Slime(GameManager game) : base(game)
        {
            Level = 1;
            // every point above 10 gives a health bonus
            Constitution = 10;
            // every point above 10 gives a dodge bonus
            Dexterity = 10;
            // health total for Capstonian; if the values reaches 0, the Capstonain is killed
            MaxHealth = 8;
            // current health for Capstonian; if the values reaches 0, the Capstonain is killed
            CurrHealth = 8;
            // max dmg Capstonian can cause
            MaxDamage = 3;
            // min dmg Capstonain can cause
            MinDamage = 1;
            // name of monster
            Name = "Slime";
            // every point above 10 gives a dmg bonus
            Strength = 10;
            MinGlory = 1;
            MaxGlory = 3;
            Sprite = game.slime;
            oldPlayerX = game.Player.X;
            oldPlayerY = game.Player.Y;
            
        }
    }
}