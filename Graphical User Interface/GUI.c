#include <gtk/gtk.h>
#include "SimpleGUIBackend.c"

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *btn_welcome;
    GtkWidget *btn_info;
    GtkWidget *btn_exit;

    gtk_init(&argc, &argv);

    // Main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GUI");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Vertical box layout
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Buttons
    btn_welcome = gtk_button_new_with_label("Show Welcome");
    g_signal_connect(btn_welcome, "clicked", G_CALLBACK(show_welcome), window);
    gtk_box_pack_start(GTK_BOX(vbox), btn_welcome, TRUE, TRUE, 5);

    btn_info = gtk_button_new_with_label("Show Info");
    g_signal_connect(btn_info, "clicked", G_CALLBACK(show_info), window);
    gtk_box_pack_start(GTK_BOX(vbox), btn_info, TRUE, TRUE, 5);

    btn_exit = gtk_button_new_with_label("Exit");
    g_signal_connect(btn_exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), btn_exit, TRUE, TRUE, 5);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
