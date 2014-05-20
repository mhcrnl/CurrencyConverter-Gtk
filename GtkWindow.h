#ifndef GTKWINDOW_H
#define GTKWINDOW_H

#include <gtk/gtk.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include "test.h"


class Window
{
public:
    Window()
    {
        create();

    }
    ~Window()
    {

    }
void create();

static void combo_selected(GtkWidget *widget, gpointer data);

static char* calculate(char* text);

static void combo_entry(GtkWidget *widget, gpointer data);

static void entry_data(GtkWidget *widget,GdkEvent* event, gpointer data);

static void callback( GtkWidget *widget,gpointer  entry2 );

static void show_about(GtkWidget *widget, gpointer data);

static GdkPixbuf *create_pixbuf(const gchar * filename);

private:

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *button;

  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *file;
  GtkWidget *quit;

  GtkWidget *helpmenu;
  GtkWidget *help;
  GtkWidget *about;


  GtkWidget *combo1;
  GtkWidget *combo2;


  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *dateLabel;

  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *dateEntry;

  GtkWidget *image;

  static int value1;
  static int value2; //for combobox

  static const char* entry1Value;
};

#endif // GTK_WINDOW_H
