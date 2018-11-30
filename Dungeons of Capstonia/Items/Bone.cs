﻿using System;
using System.Collections.Generic;
using RogueSharp;
using Capstonia.Core;

namespace Capstonia.Items
{
    public class Bone : Item
    {
        RogueSharp.Random.DotNetRandom Die = new RogueSharp.Random.DotNetRandom();

        public Bone(GameManager game) : base(game)
        {
            Name = "Bone";
            Damage = 0;
            Defense = 0;
            Value = ValuePoints();
            History = "Spooky Scary Sekelton Carcass";
            Interactive = true;
            Consumable = false;
            MaxStack = 1;
            //Sprite = game.bone;
        }

        private int ValuePoints()
        {
            return Die.Next(1, 50); // returns a value for skull object between 1 and 50 inclusive
        }

        public override void AddStat()
        {
            //Should be adding to SCORE here//
        }
        public override void RemoveStat()
        {
            //game.Messages.AddMessage("Losing is never fun, so not allowed.");
        }

        public override void Broadcast()
        {
            //https://stackoverflow.com/questions/7227413/c-sharp-variables-in-strings //
            string tmp = String.Format("Bones worth {0} glory", Value);
            game.Messages.AddMessage(tmp);
        }

        // UseItem()
        // DESC:    Overrides parent class function and uses the item
        // PARAMS:  None.
        // RETURNS: Bool. True if item is used, False otherwise.
        public override void UseItem()
        {
            //If item is picked up
            AddStat();
            game.Messages.AddMessage("Picked up " + Value + " worth of bones");

        }


    }
}
