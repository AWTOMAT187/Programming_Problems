
#define ECKEN_ANZAHL 6


#include <stdlib.h>


typedef struct hexfeld {						//DEFINITION OF AN ELEMENT OBJECT OF A HEX ARRAY
	
	unsigned int wert_ID,ring;
	struct hexfeld* node[ECKEN_ANZAHL];				// N-POINTER AT SURROUNDING ELEMENTS, DEPENDING ON NUMBER OF CORNERS OF ELEMENT OBJECT   

	void ring_ID(int element_ID) {
		ring = (unsigned int)((wert_ID - 1) / ECKEN_ANZAHL);
	}
	
}ELEMENT;


inline ELEMENT* alloc_hex_arr(unsigned int endwert) {			//ALLOCATION OF ELEMENT OBJECTS

	return (ELEMENT*)malloc(sizeof ELEMENT * endwert);
}

inline void init_hex_arr(ELEMENT* hex_arr, unsigned int endwert){	//ITERATIV FILLING AND LINKING ALLOCATED ELEMENT OBJECTS WITH EACH CORRECT NEIGHBOUR DEPENDING ON GRAPHIC 1 
	for (unsigned int i = 1; i <= endwert; i++) {
		(hex_arr++)->wert_ID = i;
		for (int j = 0; j < ECKEN_ANZAHL; j++) 
			 //hex_arr->node[j] = hex_arr + ((sizeof ELEMENT) / sizeof(char)) * (j + 1) + (hex_arr->ring)*ECKEN_ANZAHL; //hex_arr+1
			
				switch(j){
				 case 0:	 hex_arr->node[j] = hex_arr + (hex_arr->ring)*ECKEN_ANZAHL;  
					break;
				 case 1:	 hex_arr->node[j] = hex_arr + (hex_arr->ring)*ECKEN_ANZAHL+((sizeof ELEMENT) / sizeof(char));  
					break;
				 case 2:	 hex_arr->node[j] = hex_arr + ((sizeof ELEMENT) / sizeof(char));
					break;
				 case 3:	 hex_arr->node[j] = hex_arr - ((sizeof ELEMENT) / sizeof(char)); 
					break;
				 case 4:	 hex_arr->node[j] = hex_arr + (hex_arr->ring)*ECKEN_ANZAHL - ((sizeof ELEMENT) / sizeof(char)); 
					break;
				 case 5:	 hex_arr->node[j] = hex_arr + (hex_arr->ring)*ECKEN_ANZAHL*3- ((sizeof ELEMENT) / sizeof(char));
					 break;
				}
			
		}
	};

inline unsigned int prod(unsigned int anzahl_nodes, ELEMENT* hex_element) {	//ITERATIV CALCULATION OF PRODUCT OF SURROUNDING ELEMENT OBJECT VALUES 
	int produkt = 1;
	for (unsigned int i = 0; i < anzahl_nodes; i++)
		produkt *= hex_element->node[i]->wert_ID;
	return produkt;
}


	














