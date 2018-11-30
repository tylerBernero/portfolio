﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Capstonia.Core;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Capstonia.Systems
{
    //TupleList
    // Required to make our lives easier found this tutorial
    //https://whatheco.de/2011/11/03/list-of-tuples/
    // So we can create a 2D like structure for our inventory where we can keep track of how many items we have in each slot

    public class TupleList<T1,T2>: List<Tuple<T1, T2>>
    {
        public void Add(T1 item1, T2 item2)
        {
            Add(new Tuple<T1, T2>(item1, item2));
        }
    }



    // InventorySystem class
    // DESC:  Contains attributes and methods for the Inventory

    public class InventorySystem
    {
        private GameManager game;
       // public readonly List<Item> Inventory;   //public because player needs to manipulate inventory
        private readonly int maxItems = 9;
        private int currentItems = 0;

        //https://stackoverflow.com/questions/8002455/how-to-easily-initialize-a-list-of-tuples //
        public readonly TupleList<Item, int> Inventory;
        public readonly Queue<Item> potStack  = new Queue<Item>();
        public readonly Queue<Item> foodStack = new Queue<Item>();
        //coordinates for each slot on the inventory outline
        private Vector2[] coords =
        {
            new Vector2(690,50),
            new Vector2(799,50),
            new Vector2(908,50),
            new Vector2(690,100),
            new Vector2(799,100),
            new Vector2(908,100),
            new Vector2(690,150),
            new Vector2(799,150),
            new Vector2(908,150),
        };

        //coordinates for each slot on the inventory quantity outline
        private Vector2[] quantityCoords =
        {
            new Vector2(670 + 75,50 + 5),
            new Vector2(779 + 75,50 + 5),
            new Vector2(888 + 75,50 + 5),
            new Vector2(670 + 75,100 + 5),
            new Vector2(779 + 75,100 + 5),
            new Vector2(888 + 75,100 + 5),
            new Vector2(670 + 75,150 + 5),
            new Vector2(779 + 75,150 + 5),
            new Vector2(888 + 75,150 + 5),
        };


        // InventorySystem()
        // DESC:    Constructor.
        // PARAMS:  GameManager object.
        // RETURNS: None.
        public InventorySystem(GameManager game)
        {
            this.game = game;
            Inventory = new TupleList<Item, int>();

        }

        
        // AddItem()
        // DESC:    Adds item to the inventory.
        // PARAMS:  Item object.
        // RETURNS: None.
        public bool AddItem(Item iType)
        {
            //bool to keep traack of if item was successfully added to inventory or not
            bool itemAdded = false;


            //bool to know if we wrote error message already
            bool errMessage = false;

            //Cycle through inventory and look for names that match the name parameter
            //bool to help find item in list
            bool isFound = false;
            for (int x = 0; x < Inventory.Count(); x++)
            {
                Item tmp;
                int count;
                
                if(Inventory[x].Item1.Name == iType.Name)
                {
                    isFound = true;
                    //if item exists check to see if we can still stack
                    if (Inventory[x].Item2 != iType.MaxStack)
                    {
                        count = Inventory[x].Item2;
                        tmp = Inventory[x].Item1;
                        count++;
                        Inventory[x] = Tuple.Create(tmp, count); // update  tuple value
                        //store the item to our array if its a potion or food
                        if (tmp.Name == "Potion")
                        {
                            potStack.Enqueue(iType);
                        }
                        else if (tmp.Name == "Food")
                        {
                            foodStack.Enqueue(iType);
                        }

                        //Add message for successfully adding item to inventory
                        if(iType.Name != "Chest")
                        {
                            game.Messages.AddMessage("You picked up " + iType.Name);
                        }
                        

                        itemAdded = true;
                    }
                    //if can't stack
                    else
                    {
                        if (currentItems == maxItems)
                        {
                            //Only print message once
                            if(!errMessage)
                            {
                                game.Messages.AddMessage("Inventory slot full! Cannot carry any more " + iType.Name  + " to that slot");

                            }
                            
                            errMessage = true;
                        }
                        else
                        {
                            Inventory.Add(Tuple.Create(iType, 1));
                            currentItems++;
                            if (iType.Name == "Potion")
                            {
                                potStack.Enqueue(iType);
                            }
                            else if (iType.Name == "Food")
                            {
                                foodStack.Enqueue(iType);
                            }

                            //Add message for successfully adding item to inventory
                            if (iType.Name != "Chest")
                            {
                                game.Messages.AddMessage("You picked up " + iType.Name);
                            }

                            itemAdded = true;
                            break;
                        }

                    }
                }
            }


            //Add item if inventory does not contain the item and inventory is not at max capacity
            if (isFound == false)
            {
                if(currentItems == maxItems)
                {
                    //Only print message once
                    if (!errMessage)
                    {
                        game.Messages.AddMessage("Inventory full! Cannot carry any more items");
                    }

                    errMessage = true;
                }
                else
                {
                    Inventory.Add(Tuple.Create(iType, 1));
                    currentItems++;
                    if(iType.Name == "Potion")
                    {
                        potStack.Enqueue(iType);
                    }
                    else if(iType.Name == "Food")
                    {
                        foodStack.Enqueue(iType);
                    }

                    //Add message for successfully adding item to inventory
                    game.Messages.AddMessage("You picked up " + iType.Name);

                    itemAdded = true;
                }
            }

            return itemAdded;
        }

        // RemoveItem()
        // DESC:    Removes item to the inventory.
        // PARAMS:  Item object.
        // RETURNS: None.
        public void RemoveItem(int slot) //(Item iType)
        {
            int tempCount = Inventory[slot].Item2;
            tempCount--;
            if(tempCount <= 0)
            {
                Inventory.RemoveAt(slot);
                currentItems--;
                return;
            }
            Item tmp = Inventory[slot].Item1;
            Inventory[slot] = Tuple.Create(tmp, tempCount);
        }

        // useItem()
        // DESC:    attempts to use item in inventory slot
        // PARAMS:  slot number.
        // RETURNS: None.
        public void UseItem(int slot)
        {
            bool status = false;
            //Ensure there is an item in that slot
            if (0 < slot && slot < currentItems + 1)
            {
                int index = slot - 1;
                //Inventory[index].Broadcast();
                if (Inventory[index].Item1.Name == "Potion")
                {
                    status = usePotion(index);
                    if (status)
                    {
                        RemoveItem(index);//Inventory[index].Item1);
                    }
                    else
                        game.Messages.AddMessage("Cannot use while full health.");
                }
                else if(Inventory[index].Item1.Name == "Food")
                {
                    status = useFood(index);
                    if (status)
                    {
                        RemoveItem(index);//Inventory[index].Item1);
                    }
                    else
                        game.Messages.AddMessage("Cannot use while full.");
                }
                else if(Inventory[index].Item1.Name == "Book")
                {
                    Inventory[index].Item1.UseItem();
                    RemoveItem(index);//Inventory[index].Item1);
                }
                else // Weapons and Armor
                {
                    //Wear will attempt to swap places and if full instantly destroys item
                    Item placeHolder = Inventory[index].Item1;
                    RemoveItem(index);
                    game.Equip.Wear(placeHolder);
                }
            }
        }

        // usePotion()
        // DESC:    uses Potion and access the potStack Queue accordingly
        // PARAMS:  index #.
        // RETURNS: None.
        private bool usePotion(int index)
        {
            if (game.Player.CurrHealth < game.Player.MaxHealth)
            {
                Item uses = potStack.Dequeue();
                uses.UseItem();
                return true;
            }
            return false;
        }
        // useFood()
        // DESC:    uses food and access the foodStack Queue accordingly
        // PARAMS:  index #.
        // RETURNS: None.
        private bool useFood(int index)
        {

            if (game.Player.Hunger < game.Player.MaxHunger)
            {
                Item uses = foodStack.Dequeue();
                uses.UseItem();
                return true;
            }
            return false;
        }

        // GetCurrentItems()
        // DESC:    Returns value of items currently in the inventory
        // PARAMS:  None.
        // RETURNS: None.
        public int GetCurrentItems()
        {
            return currentItems;
        }

        // GetMaxItems()
        // DESC:    Returns value of max items the inventory can hold
        // PARAMS:  None.
        // RETURNS: None.
        public int GetMaxItems()
        {
            return maxItems;
        }


        // Draw()
        // DESC:    Draws the contents of the inventory to the screen
        // PARAMS:  None.
        // RETURNS: None.

        public void Draw(SpriteBatch spriteBatch)
        {
            // Draw our skeleton //
            spriteBatch.Draw(game.Outline, new Vector2(672, 1), Color.White);
            spriteBatch.DrawString(game.mainFont, "INVENTORY", new Vector2(795, 15), Color.White);

            //Draw numbers in each box
            spriteBatch.DrawString(game.mainFont, "1.", new Vector2(680, 65), Color.White);
            spriteBatch.DrawString(game.mainFont, "2.", new Vector2(790, 65), Color.White);
            spriteBatch.DrawString(game.mainFont, "3.", new Vector2(900, 65), Color.White);
            spriteBatch.DrawString(game.mainFont, "4.", new Vector2(680, 115), Color.White);
            spriteBatch.DrawString(game.mainFont, "5.", new Vector2(790, 115), Color.White);
            spriteBatch.DrawString(game.mainFont, "6.", new Vector2(900, 115), Color.White);
            spriteBatch.DrawString(game.mainFont, "7.", new Vector2(680, 165), Color.White);
            spriteBatch.DrawString(game.mainFont, "8.", new Vector2(790, 165), Color.White);
            spriteBatch.DrawString(game.mainFont, "9.", new Vector2(900, 165), Color.White);

            int index = 0; // used for accessing coordinates
            foreach (Tuple<Item,int> things in Inventory)
            {
                switch (things.Item1.Name)
                {
                    case "Armor":
                        spriteBatch.Draw(things.Item1.Sprite, coords[index], Color.White);
                        spriteBatch.DrawString(game.mainFont, "x" + things.Item2, quantityCoords[index], Color.White);
                        index++;
                        break;
                    case "Food":
                        spriteBatch.Draw(game.food, coords[index], Color.White);
                        spriteBatch.DrawString(game.mainFont, "x" + things.Item2, quantityCoords[index], Color.White);
                        index++;
                        break;
                    case "Weapon":
                        spriteBatch.Draw(things.Item1.Sprite, coords[index], Color.White);
                        spriteBatch.DrawString(game.mainFont, "x" + things.Item2, quantityCoords[index], Color.White);
                        index++;
                        break;
                    case "Book":
                        spriteBatch.Draw(things.Item1.Sprite, coords[index], Color.White);
                        spriteBatch.DrawString(game.mainFont, "x" + things.Item2, quantityCoords[index], Color.White);
                        index++;
                        break;
                    case "Potion":
                        spriteBatch.Draw(game.potion, coords[index], Color.White);
                        spriteBatch.DrawString(game.mainFont, "x" + things.Item2, quantityCoords[index], Color.White);
                        index++;
                        break;

                }
            }
        }


        // DisplayStats()
        // DESC:    Calls the broadcast function that displays stats of item at passed in slot
        // PARAMS:  slot(int)
        // RETURNS: None.
        public void DisplayStats(int slot)
        {
            bool slotEmpty = true;

            //If item exists in the slot number, boradcast its message
            //list access source: https://stackoverflow.com/questions/3949113/check-if-element-at-position-x-exists-in-the-list
            if (Inventory.ElementAtOrDefault(slot) != null)
            {
                Item tmp = Inventory[slot].Item1;
                tmp.Broadcast();
                slotEmpty = false;
            }

            //If no item in slot, output message informing player slot is empty
            if (slotEmpty == true)
            {
                game.Messages.AddMessage("That inventory slot is empty");
            }
        }


        // DropItem()
        // DESC:    Removes the item at passed in slot
        // PARAMS:  slot(int)
        // RETURNS: None.
        public void DropItem(int slot)
        {
            bool slotEmpty = true;

            //If item exists in the slot number, boradcast its message
            //list access source: https://stackoverflow.com/questions/3949113/check-if-element-at-position-x-exists-in-the-list
            if (Inventory.ElementAtOrDefault(slot) != null)
            {
                game.Messages.AddMessage("You dropped " + Inventory[slot].Item1.Name);
                RemoveItem(slot);
                slotEmpty = false;
            }

            //If no item in slot, output message informing player slot is empty
            if (slotEmpty == true)
            {
                game.Messages.AddMessage("That inventory slot is empty");
            }

        }
    }
}
