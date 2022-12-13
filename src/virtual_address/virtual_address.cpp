/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"
#include <math.h>

using namespace std;

VirtualAddress VirtualAddress::from_string(int process_id, string address) {
    // TODO: implement me

    string page = "";
    string offset = "";

    int counter = 0;

    while(counter < address.size()){
        if(counter < 10){
            page += address[counter];
        }
        else{
            offset += address[counter];
        }
        counter++;
    }


    size_t page_r = bitset<32>(page).to_ulong();
    size_t offset_r = bitset<32>(offset).to_ulong();

    return VirtualAddress(process_id, page_r, offset_r);


}


string VirtualAddress::to_string() const {
    // TODO: implement me
    //return "";

    return bitset<10>(this->page).to_string() + bitset<6>(this->offset).to_string();
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
    // TODO: implement me
    //return out;

    return (out << "PID " << address.process_id << " @ " << address.to_string() << " [page: " << address.page << "; offset: " << address.offset << "]" );
}
