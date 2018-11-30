﻿using Capstonia.Core;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using System;
using Rectangle = RogueSharp.Rectangle;

namespace Capstonia.Monsters
{
    public class Zombie : Monster
    {
        int oldPlayerX;
        int oldPlayerY;
        // constructor
        public Zombie(GameManager game) : base(game)
        {
            Level = 2;
            // every point above 10 gives a health bonus
            Constitution = 10;
            // every point above 10 gives a dodge bonus
            Dexterity = 6;
            // health total for Capstonian; if the values reaches 0, the Capstonain is killed
            MaxHealth = 10;
            // current health for Capstonian; if the values reaches 0, the Capstonain is killed
            CurrHealth = 10;
            // max dmg Capstonian can cause
            MaxDamage = 4;
            // min dmg Capstonain can cause
            MinDamage = 2;
            // name of monster
            Name = "Zombie";
            // every point above 10 gives a dmg bonus
            Strength = 11;

            MinGlory = 2;
            MaxGlory = 4;
            Sprite = game.zombie;
            oldPlayerX = game.Player.X;
            oldPlayerY = game.Player.Y;
            
        }
    }
}