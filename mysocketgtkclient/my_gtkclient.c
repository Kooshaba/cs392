/*
* Connects a client to a server using a graphic interface.
*/

#include "../lib/my_socketgtkclient.h"

GtkWidget *entries[3];
int sockfd;

/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
gboolean delete_event( GtkWidget *widget, GdkEvent  *event, gpointer data )
{
    return TRUE;
}

/* Another callback */
static void destroy( GtkWidget *widget, gpointer data )
{
    int e;

    if(e = write(sockfd, "/exit", my_strlen("/exit") + 1) < 0)
    {
        g_print("Write Failed.\n");
        exit(0);
    }
    close(sockfd);
    gtk_main_quit();
}

/*Destroys widget callback*/
void destroy_window(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

void send_message(GtkWidget *widget, gpointer data)
{
    int e;
    char *mess;

    mess = (char*)(gtk_entry_get_text((GtkEntry*)data));

    if((e = write(sockfd,mess, my_strlen(mess)+1)) < 0)
    {
        g_print("Write Failed.\n");
        exit(0);
    }
    gtk_entry_set_text((GtkEntry*)data, "");
}

/* Attempts to connect to server based on information entered in Connect window */
void connect_server(GtkWidget *widget, gpointer data)
{
    int e;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *in;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        g_print("Socket Failed");
        exit(1);
    }

    server = (struct hostent*)gethostbyname(gtk_entry_get_text((GtkEntry*)entries[0]));

    serv_addr.sin_port = htons(my_atoi(
        (char*)(gtk_entry_get_text((GtkEntry*)entries[1]))
        ));
    serv_addr.sin_family = AF_INET;
    memcpy(&(serv_addr.sin_addr.s_addr), (server->h_addr), server->h_length);

    if((e = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
    {
        g_print("Connect Failed");
        exit(1);
    } else
    {
        g_print("Connection Successful!");
    }

    if((e = write(sockfd, (char*)gtk_entry_get_text((GtkEntry*)entries[2]), my_strlen((char*)(gtk_entry_get_text((GtkEntry*)entries[2])))+1)) < 0)
    {
        g_print("Write Failed.\n");
        exit(0);
    }
    else
    {
        gtk_widget_destroy(data);
    }
}

/*Function to open the quit window */
void open_connect(GtkWidget *widget, gpointer data)
{
    GtkWidget *label_host;
    GtkWidget *text_host;
    GtkWidget *label_port;
    GtkWidget *text_port;
    GtkWidget *label_user;
    GtkWidget *text_user;
    GtkWidget *button_ok;
    GtkWidget *button_cancel;
    GtkWidget *win_connect;
    GtkWidget *connect_col1;
    GtkWidget *connect_row1;
    GtkWidget *connect_row2;
    GtkWidget *connect_row3;
    GtkWidget *connect_row4;

    /*Begin Connect Menu */
    win_connect = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    connect_col1 = gtk_vbox_new(0, 0);
    connect_row1 = gtk_hbox_new(0, 0);
    connect_row2 = gtk_hbox_new(0, 0);
    connect_row3 = gtk_hbox_new(0, 0);
    connect_row4 = gtk_hbox_new(0, 0);

    label_host = gtk_label_new("Host");
    label_port = gtk_label_new("Port");
    label_user = gtk_label_new("User");
    text_host = gtk_entry_new();
    text_port = gtk_entry_new();
    text_user = gtk_entry_new();
    button_ok = gtk_button_new_with_label("Ok");
    button_cancel = gtk_button_new_with_label("Cancel");

    entries[0] = text_host;
    entries[1] = text_port;
    entries[2] = text_user;

    gtk_box_pack_start(GTK_BOX(connect_col1), connect_row1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_col1), connect_row2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_col1), connect_row3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_col1), connect_row4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row1), label_host, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row1), text_host, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row2), label_port, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row2), text_port, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row3), label_user, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row3), text_user, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row4), button_ok, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(connect_row4), button_cancel, 0, 0, 0);

    gtk_widget_show(win_connect);
    gtk_widget_show(connect_col1);
    gtk_widget_show(connect_row1);
    gtk_widget_show(connect_row2);
    gtk_widget_show(connect_row3);
    gtk_widget_show(connect_row4);
    gtk_widget_show(label_host);
    gtk_widget_show(label_port);
    gtk_widget_show(label_user);
    gtk_widget_show(text_host);
    gtk_widget_show(text_port);
    gtk_widget_show(text_user);
    gtk_widget_show(button_ok);
    gtk_widget_show(button_cancel);

    gtk_window_set_title(GTK_WINDOW(win_connect), "Connect");

    gtk_signal_connect((GtkObject*)(button_ok), "clicked", GTK_SIGNAL_FUNC(connect_server), win_connect);
    gtk_signal_connect((GtkObject*)(win_connect), "delete-event", GTK_SIGNAL_FUNC(destroy_window), 0);
    gtk_signal_connect((GtkObject*)(button_cancel), "clicked", GTK_SIGNAL_FUNC(destroy_window), win_connect);

    gtk_container_add(GTK_CONTAINER(win_connect), connect_col1);
    /*End Connect Menu*/
}

void open_quit(GtkWidget *widget, gpointer data)
{
    GtkWidget *quit_col1;
    GtkWidget *quit_row1;
    GtkWidget *quit_row2;
    GtkWidget *win_quit;
    GtkWidget *button_yes;
    GtkWidget *button_no;
    GtkWidget *label_sure;

    /*Begin Quit Menu */
    win_quit = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    quit_row1 = gtk_hbox_new(0, 0);
    quit_row2 = gtk_hbox_new(0, 0);
    quit_col1 = gtk_vbox_new(0, 0);

    button_yes = gtk_button_new_with_label("Yes");
    button_no = gtk_button_new_with_label("Nope");
    label_sure = gtk_label_new("Are you sure you want to quit?");

    gtk_box_pack_start(GTK_BOX(quit_col1), quit_row1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(quit_col1), quit_row2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(quit_row1), label_sure, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(quit_row2), button_yes, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(quit_row2), button_no, 0, 0, 0);

    gtk_widget_show(win_quit);
    gtk_widget_show(quit_row1);
    gtk_widget_show(quit_row2);
    gtk_widget_show(quit_col1);
    gtk_widget_show(button_yes);
    gtk_widget_show(button_no);
    gtk_widget_show(label_sure);

    gtk_signal_connect((GtkObject*)(button_yes), "clicked", GTK_SIGNAL_FUNC(destroy), 0);
    gtk_signal_connect((GtkObject*)(button_no), "clicked", GTK_SIGNAL_FUNC(destroy_window), (gpointer)win_quit);

    gtk_window_set_title(GTK_WINDOW(win_quit), "Quit");
    gtk_container_add(GTK_CONTAINER(win_quit), quit_col1);
    /*End Quit Menu */
}

int main( int argc, char *argv[] )
{
    GtkWidget *win_main;
    GtkWidget *main_row1;
    GtkWidget *main_row2;
    GtkWidget *main_col1;
    GtkWidget *button_send;
    GtkWidget *button_connect;
    GtkWidget *button_quit;
    GtkWidget *text_message;

    gtk_init (&argc, &argv);

    /* Begin main window */
    win_main = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    main_row1 = gtk_hbox_new(0, 0);
    main_row2 = gtk_hbox_new(0, 0);
    main_col1 = gtk_vbox_new(0, 0);

    button_send = gtk_button_new_with_label("Send");
    button_quit = gtk_button_new_with_label("Quit");
    button_connect = gtk_button_new_with_label("Connect");
    text_message = gtk_entry_new();

    gtk_box_pack_start(GTK_BOX(main_col1), main_row1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(main_col1), main_row2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(main_row1), text_message, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(main_row1), button_send, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(main_row2), button_connect, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(main_row2), button_quit, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(win_main), main_col1);

    gtk_signal_connect((GtkObject*)button_connect, "clicked", GTK_SIGNAL_FUNC(open_connect), (gpointer) "");
    gtk_signal_connect((GtkObject*)button_quit, "clicked", GTK_SIGNAL_FUNC(open_quit), (gpointer) "");
    gtk_signal_connect((GtkObject*)win_main, "delete-event", GTK_SIGNAL_FUNC(open_quit), 0);
    gtk_signal_connect((GtkObject*)win_main, "delete-event", GTK_SIGNAL_FUNC(delete_event), 0);
    gtk_signal_connect((GtkObject*)button_send, "clicked", GTK_SIGNAL_FUNC(send_message), text_message);

    gtk_window_set_title(GTK_WINDOW(win_main), "Client");

    gtk_widget_show(win_main);
    gtk_widget_show(main_row1);
    gtk_widget_show(main_row2);
    gtk_widget_show(main_col1);
    gtk_widget_show(button_send);
    gtk_widget_show(button_connect);
    gtk_widget_show(button_quit);
    gtk_widget_show(text_message);
    /* End main window */

    gtk_main ();

    return 0;
}