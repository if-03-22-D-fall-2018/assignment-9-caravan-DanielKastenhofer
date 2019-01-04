/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "caravan.h"
#include "general.h"

#define COUNT_CARAVANS 5

typedef struct NodeImplementation* Node;

struct NodeImplementation{
  PackAnimal animal;
  struct NodeImplementation* next;
};

struct CaravanImplementation{
  int length;
  Node head;
};



Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->length = 0;
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;

  while (current!=0) {
    Node toDelete = current;
    current = current->next;
    sfree(toDelete);
    }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal == 0) return;
  Node current = caravan->head;
  Node toAdd = (Node)malloc(sizeof(struct NodeImplementation));
  toAdd->animal = animal;
  toAdd->next = 0;

  if (caravan->head == 0) {
    caravan->head = toAdd;
  }

  else{
    while (current->next != 0) {
      current = current->next;
    }
    current->next = toAdd;
  }

  add_to_caravan(animal, caravan);
  caravan->length++;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal == 0) return;
  Node current = caravan->head;
  while (current->next != 0 && current->next->animal != animal) {
    current = current->next;
  }
  
  if (current->next->animal == animal) {
    Node toRemove = current->next;
    current->next = toRemove->next;
    sfree(toRemove);
    remove_from_caravan(animal, caravan);
    caravan->length--;
  }
    return;
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{

}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan){

}
