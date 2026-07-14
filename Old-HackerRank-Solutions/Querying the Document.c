
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
return document[k-1];
}

char**** get_document(char* text) {
char**** doc = malloc(sizeof(char***));
    doc[0] = malloc(sizeof(char**));
    doc[0][0] = malloc(sizeof(char*));
    
    int p = 0, s = 0, w = 0, c = 0;
    
    while (*text) {
        if (*text == ' ') {
            w++;
            c = 0;
            doc[p][s] = realloc(doc[p][s], (w + 1) * sizeof(char*));
        } else if (*text == '.') {
            s++;
            w = 0;
            c = 0;
            doc[p] = realloc(doc[p], (s + 1) * sizeof(char**));
            doc[p][s] = malloc(sizeof(char*));
        } else if (*text == '\n') {
            p++;
            s = 0;
            w = 0;
            c = 0;
            doc = realloc(doc, (p + 1) * sizeof(char***));
            doc[p] = malloc(sizeof(char**));
            doc[p][0] = malloc(sizeof(char*));
        } else {
            if (c == 0) {
                doc[p][s][w] = malloc(2 * sizeof(char));
            } else {
                doc[p][s][w] = realloc(doc[p][s][w], (c + 2) * sizeof(char));
            }
            doc[p][s][w][c] = *text;
            doc[p][s][w][c + 1] = '\0';
            c++;
        }
        text++;
    }
    return doc;
}
