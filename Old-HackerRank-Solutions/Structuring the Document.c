truct document get_document(char* text) {
    struct document doc;
    doc.data = NULL;
    doc.paragraph_count = 0;
     
    struct paragraph* cur_para = NULL;
    struct sentence* cur_sent = NULL;
    
    char* word_start = NULL;
    char* s = text;
    
    while (1) {
        if (*s != ' ' && *s != '.' && *s != '\n' && *s != '\0') {
            if (!word_start) {
                word_start = s;
            }
        }
        if (*s == ' ' || *s == '.' || *s == '\n' || *s == '\0') {
            if (word_start) {
                if (doc.paragraph_count == 0) {
                    doc.paragraph_count = 1;
                    doc.data = malloc(sizeof(struct paragraph));
                    doc.data[0].data = NULL;
                    doc.data[0].sentence_count = 0;
                }
                cur_para = &doc.data[doc.paragraph_count - 1];
                if (cur_para->sentence_count == 0) {
                    cur_para->sentence_count = 1;
                    cur_para->data = malloc(sizeof(struct sentence));
                    cur_para->data[0].data = NULL;
                    cur_para->data[0].word_count = 0;
                }
                cur_sent = &cur_para->data[cur_para->sentence_count - 1];
                cur_sent->word_count++;
                cur_sent->data = realloc(cur_sent->data, cur_sent->word_count * sizeof(struct word));
                char temp = *s;
                *s = '\0'; 
                cur_sent->data[cur_sent->word_count - 1].data = strdup(word_start);
                *s = temp;
                word_start = NULL;
            }
            
            if (*s == '.') {
                cur_para->sentence_count++;
                cur_para->data = realloc(cur_para->data, cur_para->sentence_count * sizeof(struct sentence));
                cur_para->data[cur_para->sentence_count - 1].data = NULL;
                cur_para->data[cur_para->sentence_count - 1].word_count = 0;
            }
            else if (*s == '\n') {
                if (cur_para && cur_para->sentence_count > 0 && cur_para->data[cur_para->sentence_count - 1].word_count == 0) {
                    cur_para->sentence_count--;
                }
                doc.paragraph_count++;
                doc.data = realloc(doc.data, doc.paragraph_count * sizeof(struct paragraph));
                doc.data[doc.paragraph_count - 1].data = NULL;
                doc.data[doc.paragraph_count - 1].sentence_count = 0;
            }
        }
        if (*s == '\0') {
            break;
        }
        s++;
    }
    if (doc.paragraph_count > 0) {
        struct paragraph* last_p = &doc.data[doc.paragraph_count - 1];
        if (last_p->sentence_count > 0 && last_p->data[last_p->sentence_count - 1].word_count == 0) {
            last_p->sentence_count--;
        }
        if (last_p->sentence_count == 0) {
            doc.paragraph_count--;
        }
    }
    return doc;
}
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}
