void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_node, *temp;

/* Check if the list is empty or has only one element */
if (!list || !(*list) || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
next_node = current->next;

/* If current node is smaller than the previous node, swap them */
while (current->prev && current->n < current->prev->n)
{
/* Swap current and current->prev nodes */
temp = current->prev;
if (temp->prev)
temp->prev->next = current;
else
*list = current; /* If current is the head, update list pointer */
current->prev = temp->prev;
temp->next = current->next;
if (current->next)
current->next->prev = temp;
current->next = temp;
temp->prev = current;

print_list(*list);  /* Print list after swap */
}

current = next_node;
}
}
