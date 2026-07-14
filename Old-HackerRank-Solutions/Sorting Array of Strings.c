
int lexicographic_sort(const char* a, const char* b) {
return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
    
  int hash_a[26] = {0};
    int hash_b[26] = {0};
    int count_a = 0;
    int count_b = 0;
      for (int i = 0; a[i] != '\0'; i++) {
        int index = a[i] - 'a';
        if (hash_a[index] == 0) {
            hash_a[index] = 1;
            count_a++;
        }
    }
    for (int i = 0; b[i] != '\0'; i++) {
        int index = b[i] - 'a';
        if (hash_b[index] == 0) {
            hash_b[index] = 1;
            count_b++;
        }
    }
    if (count_a != count_b) {
        return count_a - count_b;
    }
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int res=strlen(a)-strlen(b);
    if(res==0){
        return strcmp(a,b);
        
    }return res;

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
}}}}

