﻿using Capstonia.Core;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using System;
using Rectangle = RogueSharp.Rectangle;

namespace Capstonia.Monsters
{
    public class Minotaur : Monster
    {
        int oldPlayerX;
        int oldPlayerY;
        // constructor
        public Minotaur(GameManager game) : base(game)
        {
            Level = 5;
            // every point above 10 gives a health bonus
            Constitution = 13;
            // every point above 10 gives a dodge bonus
            Dexterity = 10;
            // health total for Capstonian; if the values reaches 0, the Capstonain is killed
            MaxHealth = 15;
            // current health for Capstonian; if the values reaches 0, the Capstonain is killed
            CurrHealth = 15;
            // max dmg Capstonian can cause
            MaxDamage = 10;
            // min dmg Capstonain can cause
            MinDamage = 5;
            // name of monster
            Name = "Minotaur";
            // every point above 10 gives a dmg bonus
            Strength = 16;

            MinGlory = 5;
            MaxGlory = 9;
            Sprite = game.minotaur;
            oldPlayerX = game.Player.X;
            oldPlayerY = game.Player.Y;
            
        }
    }
}