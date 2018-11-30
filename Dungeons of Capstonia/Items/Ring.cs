﻿using System;
using System.Collections.Generic;
using RogueSharp;
using Capstonia.Core;

namespace Capstonia.Items
{
    public class Ring : Item
    {

        public Ring(GameManager game) : base(game)
        {
            Name = "Ring";
            Damage = 0;
            Defense = 0;
            Value = ValuePoints();
            History = "Useless piece of metal";
            Interactive = true;
            Consumable = false;
            MaxStack = 1;
            //Sprite = game.ring;
        }

        private int ValuePoints()
        {
            return Capstonia.GameManager.Random.Next(1, 25); // returns a value for skull object between 1 and 50 inclusive
        }

        public override void AddStat()
        {
            //Should be adding to SCORE here//
        }
        public override void RemoveStat()
        {
            game.Messages.AddMessage("Losing is never fun, so not allowed.");
        }

        public override void Broadcast()
        {
            //https://stackoverflow.com/questions/7227413/c-sharp-variables-in-strings //
            string tmp = String.Format("Ring worth {0} glory", Value);
            game.Messages.AddMessage(tmp);
        }

        // UseItem()
        // DESC:    Overrides parent class function and uses the item
        // PARAMS:  None.
        public override void UseItem()
        {
            //If item is picked up
            AddStat();
            game.Messages.AddMessage("Found a ring worth " + Value + " value");

        }


    }
}
