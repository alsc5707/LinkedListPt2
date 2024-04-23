
#include "BrowserHistory.hpp"

BrowserHistory::BrowserHistory()
{
    // No changes needed
}

BrowserHistory::~BrowserHistory()
{
    // No changes needed
}

/*
 * Purpose: Has to detect if a defect is present in the linkedlist pointed by head
 * @param none
 * @return integer length of defect if one exists. If defect not present return -1
 */
int BrowserHistory::findDefectLength(){
    // TODO START =============================================
    WebPage *slow = head;
    WebPage *fast = head;
    while (fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast){
            int x =1;
            slow = slow->next;
            while(slow != fast){
                x++;
                slow = slow->next;
            }
            return x;
        }
    }
    return -1;
    // TODO END ==================================================
}

/*
 * Purpose: Has to remove all the WebPage nodes from [start, end] inclusive.
 * Has to print appropriate messages on cout like below if the linkedlist is empty
 * or if the values of start/ end are improper
 * follow the same order for couts in the writeup - check empty list first, then check wrong start/end values
 * @param integers start and end (1 based indexing not 0 based)
 * @return none
 */
void BrowserHistory::removeWebPages(int start, int end){

    // TODO START ===================================================
    if(head == nullptr){
        cout << "Browsing history is Empty" << endl;
        return;
    }
    if (start > end || start < 1){
        cout << "Invalid start or end values" << endl;
        return;
    }
    WebPage *prev = nullptr;
    WebPage *current = head;
    int idx = 1;
    while (idx < start && current != nullptr){
        prev = current;
        current = current->next;
        idx +=1;
    }
    if(current == nullptr){
        cout << "Invalid start or end values" << endl;
        return;
    }
    WebPage *beginning = current;
    WebPage *Rend = beginning;
    while(Rend->next != nullptr && idx < end){
        Rend = Rend->next;
        idx +=1;
    }
    if (idx < end){
        cout << "Invalid start or end values" << endl;
        return;
    }
    if (prev != nullptr){
        prev->next = Rend->next;
    } else {
        head = Rend->next;
    }
    while (beginning != Rend->next){
        WebPage *x = beginning;
        beginning = beginning->next;
        delete x;
    }
    // TODO END ===================================================
}


/*
 * Purpose: Interweave the webpages alternatively into a new linkedlist 
 * starting with the first webpage in the list one
 * Assign the head of the new interweaved list to the head of this BrowserHistory
 * DO NOT create new nodes and copy the data, just use the same nodes from one and two and change pointers
 * If one of them runs out of length append the remaining of the other one at end
 * @param two linkedlist heads one and two
 * @return none
 */
void BrowserHistory::mergeTwoHistories(WebPage *headOne, WebPage * headTwo){

    // TODO START =============================================
    if(headOne == nullptr){
        head = headTwo;
        return;
    } else if (headTwo == nullptr){
        head = headOne;
        return;
    }
    head = headOne;
    WebPage *next1 = headOne->next;
    WebPage *next2 = headTwo;
    WebPage *curr = headOne;
    while (next1 != nullptr && next2 != nullptr){
        curr->next = next2;
        next2 = next2->next;
        curr = curr->next;
        if(next1!=nullptr){
            curr->next = next1;
            next1 = next1->next;
            curr = curr->next;

        }
    }
    if (next2 != nullptr){
        curr->next = next2;
    }
    // TODO END ==================================================
}
