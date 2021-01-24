#include "queue.h"
static node *create_node(int id, int time, node *link)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->link = link;
    new_node->id = id;
    new_node->time = time;
    return new_node;
}
void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->number_of_nodes = 0;
    ptr_list->tail = NULL;
}
const int node_get_id(node *node_ptr)
{
    return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
    return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
    struct node *ins = ptr_list->head;
    struct node *box = create_node(id, time, NULL);
    if (ptr_list->number_of_nodes == 0)
    {
        ptr_list->head = box;
    }
    else
    {
        while (ins->link != NULL)
        {
            ins = ins->link;
        }
        ins->link = box;
        box->link = NULL;
    }
    ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
    struct node *node_todel = ptr_list->head;

    if (ptr_list->number_of_nodes == 0)
    {
        list_destroy(ptr_list);
    }
    else
    {
        ptr_list->head = node_todel->link;
        free(node_todel);
    }
    ptr_list->number_of_nodes--;
}

void list_destroy(List *ptr_list)
{
    struct node *dest = ptr_list->head;
    struct node *dest_after = NULL;
    while (dest != NULL)
    {
        dest_after = dest;
        dest = dest->link;
        ptr_list->number_of_nodes--;
        free(dest_after);
    }
    free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
    queue_list->ptr_list = malloc(sizeof(struct list));
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
    list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr)
{

    list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
    if (ptr->ptr_list->head = NULL)
        return 1;
    return 0;
}

void queue_peek(Queue *ptr)
{
    ptr->ptr_list->number_of_nodes == 0 ? printf("EMPTY QUEUE\n") : printf("%d %d\n", ptr->ptr_list->head->id, ptr->ptr_list->head->time);
}

void queue_destroy(Queue *ptr)
{
    list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
    struct node *before;
    struct node *test = ptr_queue->ptr_list->head;
    struct node *after = ptr_queue->ptr_list->head;
    int sum = 0, resultant, totalTime = 0;

    while (test != NULL)
    {
        totalTime = totalTime + test->time;
        test = test->link;
    }

    if (t > totalTime)
    {
        ptr_queue->ptr_list->number_of_nodes = 0;
        printf("EMPTY QUEUE\n");
    }
    else
    {
        while (sum < t)
        {
            before = after;
            resultant = after->id;
            sum = sum + (after->time);
            after = after->link;
            ptr_queue->ptr_list->head = before;
        }
        printf("%d\n", resultant);
    }
}
