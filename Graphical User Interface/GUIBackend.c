#include <gtk/gtk.h>

// Function to display a welcome message
void show_welcome(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(data),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "Welcome to the Simple GUI!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Function to display info message
void show_info(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(data),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "This is a simple GUI created using GTK in C.");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
