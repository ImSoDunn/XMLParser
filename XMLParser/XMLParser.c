#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>


void parseXML(xmlNodePtr node){
        xmlNodePtr current = node;

        while (current != NULL){
                if (current->type == XML_ELEMENT_NODE){
                        if (xmlStrcmp(current->name, (const xmlChar *)"title") == 0){
                                printf("Title: %s\n", xmlNodeGetContent(current));
                        }
                }


        //Recursive to parse child nodes
        parseXML(current->children);

        //Set to next for loop
        current = current->next;

        }
}




int main() {
        xmlDocPtr doc;
        xmlNodePtr root;

        // Parse the XML file
        doc = xmlReadFile("catalog.xml", NULL, 0);

        if (doc == NULL) {
                fprintf(stderr, "Failed to parse the document.\n");
                return 1;
        }

        // Get the root element, this will be a xmlNodePtr
        root = xmlDocGetRootElement(doc);

        //Parse the XML for the Title
        parseXML(root);

        // Free the Resources
        xmlFreeDoc(doc);
        xmlCleanupParser();

        //Test Print Statement
        printf("Hello I am a change to the source code");
        
        return 0;
}
