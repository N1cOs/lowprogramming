typedef struct linked_list{
  struct linked_list *next_element;
  int value;
} linked_list;

linked_list * list_create(int value){
  linked_list *another_one = (linked_list*) malloc(sizeof(linked_list));
  another_one->value = value;
  another_one->next_element = NULL;
  return another_one;
}

void list_add_front(linked_list **list, int value){
  linked_list *pr_first_element = *list;
  *list = list_create(value);
  (*list)->next_element = pr_first_element;
}

void list_add_back(linked_list **list, int value){
  linked_list *new_element = list_create(value);
  linked_list *current_element = *list;
  while(current_element->next_element){
    current_element = current_element->next_element;
  }
  current_element->next_element = new_element;
}

void list_free(linked_list *list){
  linked_list *element = list;
  while(element){
    free(element);
    element = element->next_element;
  }
}

int list_length(linked_list *list){
  linked_list *element = list;
  int length = 0;
  while(element){
    length++;
    element = element->next_element;
  }
  return length;
}

linked_list * list_node_at(linked_list *list, int index){
  if(index > list_length(list) - 1){
    return NULL;
  }
  linked_list *element = list;
  for(; index > 0; index--){
    element = element->next_element;
  }
  return element;
}

int list_get(linked_list *list, int index){
  return list_node_at(list, index)->value;
}

unsigned long list_sum(linked_list *list){
  linked_list *element = list;
  unsigned long sum = 0;
  while(element){
    sum += element->value;
    element = element->next_element;
  }
  return sum;
}


// int main(){
//   linked_list *list = NULL;
//   int value;
//   while(scanf(" %d ", &value) != EOF){
//     if(!list){
//       list = (linked_list*) malloc(sizeof(linked_list));
//       list->value = value;
//     }
//     else{
//       list_add_front(&list, value);
//     }
//   }
//   printf("Sum of elements - %lu\n", list_sum(list));
//   printf("%s", "Elements of the list - ");
//   int length = list_length(list);
//   int i;
//   for(i = 0; i < length; i++){
//     printf("%d ", list_node_at(list, i)->value);
//   }
//   printf("\n");
//   list_free(list);
//   return 0;
// }
