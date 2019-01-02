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

struct CaravanImplementation{
  int length;
  PackAnimal animal;
  struct CaravanImplementation* next;
};

Caravan head = (Caravan)malloc(sizeof(struct CaravanImplementation));

Caravan new_caravan()
{
  head->animal = 0;
  head->length = 0;
  head->next = 0;

  return head;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Caravan current = head;

  while (current!=0) {
    if (caravan == head) {
      sfree(head);
      return;
    }

    else if (caravan == current->next) {
      current->next = caravan->next;
      sfree(caravan);
      return;
    }
  }
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal!=0 && get_caravan(animal) != 0) {
    caravan->animal = animal;
    caravan->length++;
    add_to_caravan(animal, caravan);
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  caravan->animal = 0;
  caravan->length--;
  remove_from_caravan(animal, caravan);
}

int get_caravan_load(Caravan caravan)
{
  int load;
  Caravan current = head->next;
  while (current!=0) {
    load+=get_load(current->animal);
    current = current->next;
  }
  return load;
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
