
struct box
{
    int length;
    int width;
    int height;
	/**
	* Define three fields of type int: length, width and height
	*/
};

typedef struct box box;

int get_volume(box b) {
   return b.length*b.width*b.height;
	/**
	* Return the volume of the box
	*/
}

int is_lower_than_max_height(box b) {
    int max_height=41;
    if (b.height<max_height){
      return 1;  
    }else{
        return 0;
    }
	/**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
}

