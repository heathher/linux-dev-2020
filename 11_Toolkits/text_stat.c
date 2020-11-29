#include <stdio.h>
#include <glib.h>

#define MAX_LENGTH 80

gboolean finder(gpointer key, gpointer value, gpointer word) 
{
    return !g_ascii_strcasecmp(key, word);
}

gint cmp(gconstpointer x, gconstpointer y, gpointer word_counter) 
{
    gpointer x_ptr = g_hash_table_find(word_counter, (GHRFunc)finder, (gpointer)x);
    gpointer y_ptr = g_hash_table_find(word_counter, (GHRFunc)finder, (gpointer)y);
    return GPOINTER_TO_INT(y_ptr) - GPOINTER_TO_INT(x_ptr);
}

void print(gpointer word, gpointer counter) 
{
  gpointer count = g_hash_table_find(counter, (GHRFunc)finder, word);
  printf("%d: %s\n", GPOINTER_TO_INT(count), (char* )word);
}

int main(int argc, char** argv)
{
    if (argc != 2) 
    {
        printf("No file for processing\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        printf("Can't open file %s\n", argv[1]);
        return 1;
    }
    gchar line[MAX_LENGTH + 1];

    GHashTable* word_counter = g_hash_table_new(g_str_hash, g_str_equal);
  
    while (fgets(line, MAX_LENGTH + 1, file)) 
    {
        line[strlen(line) - 1] = '\0';
        gchar** words = g_strsplit(line, " ", -1);
        for (int i = 0; words[i]; ++i) 
        {
            gchar* word = g_strdup(words[i]);
            int* freq = g_hash_table_lookup(word_counter, word);
            if (freq)
            {
                g_hash_table_replace(word_counter, word, GINT_TO_POINTER(GPOINTER_TO_INT(freq) + 1));
            } else {
                g_hash_table_insert(word_counter, word, GINT_TO_POINTER(1));
            }
        }
        g_strfreev(words);
    }
    GList* sorted_words = g_hash_table_get_keys(word_counter);
    sorted_words = g_list_sort_with_data(sorted_words, (GCompareDataFunc)cmp, word_counter);

    g_list_foreach(sorted_words, print, word_counter);
    g_list_free(sorted_words);
    g_hash_table_destroy(word_counter);

    fclose(file);

    return 0;
}