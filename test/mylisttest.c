/*
Main Method to Test MyList, a linked list
*/

#include "../lib/mylist.h"

#ifndef SEP
#define SEP my_str("\n**********************\n");
#endif

#ifndef NL
#define NL my_char('\n');
#endif

int main()
{

    t_node* head = NULL;
    /*
    traverse_char   (NULL);
    traverse_string (NULL);
    traverse_int    (NULL);
    SEP
    new_node(NULL,NULL);
    new_node(0,NULL);
    SEP
    add_node(NULL,NULL);
    add_node(NULL,&head);
    SEP
    add_elem(NULL,NULL);
    add_elem(NULL,&head);
    SEP
    add_node_at(NULL,NULL,0);
    add_node_at(NULL,&head,0);
    SEP
    remove_node(NULL);
    remove_node(&head);
    SEP
    remove_node_at(NULL,0);
    remove_node_at(&head,0);
    SEP
    remove_last(NULL);
    remove_last(&head);
    SEP
    count_nodes(NULL);
    SEP
    empty_list(NULL);
    empty_list(&head);
    SEP
    node_at(NULL,0);
    elem_at(NULL,0);
    SEP
    */
/*
    //Integers / chars
    char* c = "0123456";

    //Checks add node and new node
    //append(new_node(&c[1],NULL),&head);

    t_node* e = new_node(&c[0],NULL);


    add_elem(&c[3],&head); //3
    add_elem(&c[0],&head); //0 3
    add_elem(&c[1],&head); //1 0 3

    append(new_node(&c[2],NULL),&head); //1 0 3 2

    add_node_at(new_node(&c[4],NULL),&head,2);  //1 0 4 3 2
    add_node_at(new_node(&c[5],NULL),&head,-1); //5 1 0 4 3 2
    add_node_at(new_node(&c[6],NULL),&head,17); //5 1 0 4 3 2 6

    traverse_char(head);
    my_char('\n');
    traverse_int(head);
    my_char('\n');

    my_char(*(char*)remove_node(&head)); //5 //1 0 4 3 2 6
    my_char('\n');
    my_char(*(char*)remove_node_at(&head,2)); //4 //1 0 3 2 6
    /*my_char(*(char*)remove_node_at(&head,-1)); // 1 //0 3 2 6
    my_char(*(char*)remove_node_at(&head,17)); //6 //0 3 2
    my_char(*(char*)remove_node_at(&head,2)); //2 //0 3
    my_char(*(char*)remove_last(&head));
    my_str("-->");
    my_int(count_nodes(head));
    my_str("<--");

    //Checks node at
    my_char(*(char*)elem_at(head,0));
    my_char(*(char*)elem_at(head,-3));
    my_char(*(char*)elem_at(head,14));

    my_char('\n');
    traverse_char(head);
    my_char('\n');
    traverse_int(head);
    my_char('\n');

    empty_list(&head);

    my_char('\n');
    traverse_char(head);
    my_char('\n');
    traverse_int(head);
    my_char('\n');*/
    //Strings

    t_node* e = new_node("32",head);

    //Checks add node and new node
    add_elem("#",&head);
    add_elem(")",&head);
    add_elem("!",&head);

    append(new_node("@",NULL),&head);

    add_node_at(new_node("$",NULL),&head,2);
    add_node_at(new_node("5",NULL),&head,-1);
    add_node_at(new_node("^",NULL),&head,17);

    traverse_string(head);
    my_char('\n');

    my_str(remove_node(&head));
    my_str(remove_node_at(&head,2));
    my_str(remove_last(&head));

    my_int(count_nodes(head));

    //Checks node at
    my_str(elem_at(head,0));
    my_str(elem_at(head,-3));
    my_str(elem_at(head,14));

    traverse_string(head);
    my_char('\n');

    empty_list(&head);

    /*
    int arr[10] = {4, 65, 32, 1, 68, 23, 83, 12, 6, 82};
    t_node *head;
    int i;
    int n;
    int *pi;

    SEP
    head = NULL;
    for (i = 0; i < 5; i++)
        add_node(new_node(&arr[i], NULL), &head);
    for (; i < 10; i++)
        add_elem(&arr[i], &head);
    traverse_int(head);
    NL my_int(count_nodes(head));
    n = 5;
    add_node_at(new_node(&n, NULL), &head, 2);
    SEP
    traverse_int(head);
    my_char('\n');
    add_node(new_node(&n, NULL), &head);
    add_node_at(new_node(&n, NULL), &head, 0);
    add_node_at(new_node(&n, NULL), &head, 34);
    append(new_node(&n, NULL), &head);
    pi = (int*)remove_node(&head);
    my_int(*pi);
    my_char('\n');
    traverse_int(head);
    SEP

    pi = (int*)remove_node_at(&head, 4);
    my_int(*pi);
    my_char('\n');
    traverse_int(head);
    my_char('\n');
    pi = (int*)remove_node_at(&head, 0);
    my_int(*pi);
    my_char('\n');
    pi = (int*)remove_node_at(&head, 35);
    my_int(*pi);
    my_char('\n');
    traverse_int(head);
    SEP
    pi = (int*)remove_last(&head);
    my_int(*pi);
    my_char('\n');
    traverse_int(head);
    SEP
    my_int(count_nodes(head));
    my_char('\n');
    empty_list(&head); NL
    traverse_int(head);
    */

    /*
    SEP
    t_node *node1 = new_node(my_strdup("hey"), NULL);
    t_node *node2 = new_node(my_strdup("there"), NULL);
    t_node **head = &node2;
    add_node(node1, head);
    append(new_node(my_strdup("oh"), NULL), head);
    traverse_string(*head);
    SEP
    add_node_at(new_node(my_strdup("BLAH"), NULL), head, 1);
    traverse_string(*head);
    SEP
    add_elem(my_strdup("eeee"), head);
    traverse_string(*head);
    SEP
    traverse_string(remove_node(head));
    NL
    traverse_string(*head);
    SEP
    remove_last(head);
    traverse_string(*head);
    SEP
    t_node *test = remove_node_at(head, 1);
    traverse_string(test);
    NL
    traverse_string(*head);
    SEP
    add_node_at(new_node(my_strdup("ADD_NODE_AT"), NULL), head, 10);
    traverse_string(*head);
    SEP
    my_int(count_nodes(*head));
    SEP
    empty_list(head);
    traverse_string(*head);
    SEP
    int a[5] = {1,2,3,4,5};
    t_node *n = new_node(&a[0], NULL);
    t_node *n1 = new_node(&a[1], NULL);
    t_node **h = &n1;
    add_node(n, h);
    traverse_int(*h);
    SEP
    char b[5] = {'a', 'b', 'c', 'd', 'e'};
    t_node *m = new_node(&b[0], NULL);
    t_node *m1 = new_node(&b[1], NULL);
    t_node **i = &m1;
    add_node(m, i);
    traverse_char(*i);
    SEP
    remove_node_at(NULL, 0);
    */

    return 0;
}