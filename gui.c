#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

void analizar(GtkWidget *widget, gpointer data) {
    GtkTextBuffer *input_buffer = GTK_TEXT_BUFFER(data);
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(input_buffer, &start, &end);

    gchar *text = gtk_text_buffer_get_text(input_buffer, &start, &end, FALSE);

    FILE *f = fopen("temp.txt", "w");
    fprintf(f, "%s", text);
    fclose(f);

    system("simplelex temp.txt > output.txt");

    GtkWidget *dialog = gtk_message_dialog_new(
        NULL,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "Análisis léxico completado.\nRevisa el archivo output.txt"
    );
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    g_free(text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Analizador Léxico");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_box_pack_start(GTK_BOX(box), text_view, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Analizar");
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    g_signal_connect(button, "clicked", G_CALLBACK(analizar), buffer);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
