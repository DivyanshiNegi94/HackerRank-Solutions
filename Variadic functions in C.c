
int  sum (int count,...) {
va_list args;
    va_start(args, count);
    int total = 0;
    for (int i=0;i<count;i++) {
        total+=va_arg(args,int);
    }
    va_end(args);
    return total;
}

int min(int count,...) {
va_list args;
    va_start(args, count);
    int minimum= MAX_ELEMENT; 
    for (int i= 0; i<count;i++) {
        int current =va_arg(args, int);
        if (current<minimum) {
            minimum =current;
        }
    }va_end(args);
    return minimum;
}

int max(int count,...) {

    
    va_list args;
    va_start(args, count);
    int maximum =MIN_ELEMENT;
    for (int i=0; i< count; i++) {
        int current=va_arg(args, int);
        if (current>maximum) {
            maximum=current;
        }
    }
    va_end(args);
    return maximum;
}

