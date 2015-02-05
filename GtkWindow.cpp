#include "GtkWindow.h"
#include "XMLCurrency.h"

Currency currency;

int  Window :: value1=-1;
int Window :: value2=-1; //for combobox

const char* Window :: entry1Value="1";

void Window::create()
{
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_window_set_title(GTK_WINDOW(window), "Currency Converter");
  gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("currency-icon.png"));
  table = gtk_table_new(5, 3, FALSE);




//Menu options
  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  helpmenu = gtk_menu_new();

  file = gtk_menu_item_new_with_label("File");
  quit = gtk_menu_item_new_with_label("Quit");


  help = gtk_menu_item_new_with_label("Help");
  about = gtk_menu_item_new_with_label("About");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);

  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);

  gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

//ComboBox options

  combo1 = gtk_combo_box_text_new();
  combo2 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "HR Kuna");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Euro");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "US Dollar");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Swiss Franc");

  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "HR Kuna");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Euro");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "US Dollar");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Swiss Franc");


 //Label options

  label1 = gtk_label_new("Currency I Have");
  label2 = gtk_label_new("Currency I Want");
  label3 = gtk_label_new("Amount");
  label4 = gtk_label_new("Converted");

  dateLabel = gtk_label_new(Currency::date.c_str());
  gtk_widget_modify_font (dateLabel,  pango_font_description_from_string (" 14"));

//EntryText options

  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();


// Button options


  image= gtk_image_new_from_stock(GTK_STOCK_EXECUTE,GTK_ICON_SIZE_LARGE_TOOLBAR);
  button=gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button),image);

 //Putting widgets on the table
  gtk_table_attach(GTK_TABLE(table), menubar, 0, 3, 0, 1,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 0, 0 );

  gtk_table_attach(GTK_TABLE(table), combo1, 0, 1, 2, 3,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo2, 2, 3, 2, 3,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5, 5);


gtk_table_attach(GTK_TABLE(table), dateLabel, 1, 2, 1, 2,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5, 5);

  gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 1, 2,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 15, 15);
  gtk_table_attach(GTK_TABLE(table), label2, 2, 3, 1, 2,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 15, 15);
  gtk_table_attach(GTK_TABLE(table), label3, 0, 1, 3, 4,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK) , 5, 5);
  gtk_table_attach(GTK_TABLE(table), label4, 2, 3, 3, 4,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK) , 5, 5);

  gtk_table_attach(GTK_TABLE(table),entry1, 0, 1, 4, 5,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5,10);
  gtk_table_attach(GTK_TABLE(table),entry2, 2, 3, 4, 5,
     (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5, 10 );

  gtk_table_attach(GTK_TABLE(table),button, 1, 2, 3, 4,
      (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 5, 5);


 gtk_table_set_row_spacing( GTK_TABLE(table),0,50);
 gtk_table_set_row_spacing( GTK_TABLE(table),2,50);
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);

  g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);

 g_signal_connect(G_OBJECT(combo1), "changed",G_CALLBACK(combo_selected), &value1);

 g_signal_connect(G_OBJECT(combo2), "changed",G_CALLBACK(combo_selected), &value2);

 g_signal_connect (button, "clicked",G_CALLBACK (callback), entry2);

 g_signal_connect(G_OBJECT(combo1), "changed",G_CALLBACK(combo_entry), entry1);

  g_signal_connect(G_OBJECT(about), "button-press-event",G_CALLBACK(show_about), NULL);

 g_signal_connect(G_OBJECT(entry1),"key-release-event",G_CALLBACK(entry_data),NULL);

  g_signal_connect(G_OBJECT(about), "activate",G_CALLBACK(show_about), NULL);

  g_signal_connect(G_OBJECT(quit), "activate",G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

    }

GdkPixbuf* Window:: create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

void Window::combo_selected(GtkWidget *widget, gpointer data)
{
  int *value=(int*)data;
  *value=gtk_combo_box_get_active(GTK_COMBO_BOX(widget));

}

 char* Window::calculate(char* text)
{

     char buf[5];
     double num=atof(text);

     if(value1==0)
     {
         if(value2==0)
            num=num*1;

         else if(value2==1)
            num=num/currency.EurHr();

         else if(value2==2)
            num=num/currency.UsaHr();

         else if(value2==3)
            num=num/currency.SuiHr();
     }
     if(value1==1)
     {
         if(value2==0)
            num=num*currency.EurHr();

         else if(value2==1)
            num=num*1;

        else if(value2==2)
            num=num*currency.EurUsa();

         else if(value2==3)
            num=num*currency.EurSui();
     }
     if(value1==2)
     {
         if(value2==0)
            num=num*currency.UsaHr();

         else if(value2==1)
            num=num/currency.EurUsa();

        else if(value2==2)
            num=num*1;

         else if(value2==3)
            num=num*currency.UsaSui();
     }

     if(value1==3)
     {
         if(value2==0)
            num=num*currency.SuiHr();

         else if(value2==1)
            num=num/currency.EurSui();

        else if(value2==2)
            num=num/currency.UsaSui();

         else if(value2==3)
            num=num*1;
     }

     sprintf(buf,"%.3f",num);
     text=buf;

     return text;//strdup(text);
}

 void Window::combo_entry(GtkWidget *widget, gpointer data)
{

  if(gtk_combo_box_get_active(GTK_COMBO_BOX(widget))!=-1)
    gtk_entry_set_text(GTK_ENTRY(data), entry1Value);


}
 void Window::entry_data(GtkWidget *widget,GdkEvent* event, gpointer data)
{

 entry1Value=gtk_entry_get_text(GTK_ENTRY(widget));


}
void Window::callback( GtkWidget *widget,gpointer  entry2 )
{
   gtk_entry_set_text(GTK_ENTRY(entry2),calculate(const_cast<char*>(entry1Value)));

}

void Window::show_about(GtkWidget *widget, gpointer data)
{
 gtk_show_about_dialog (NULL,"program-name", "Currency Converter",
                             "title", "About Currency Converter",
                             "version","1.0",
                             "copyright","(c) Ivica Tokic",
                             "comments","Program for converting currencies",NULL);
}


