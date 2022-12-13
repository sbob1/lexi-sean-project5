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
    //return VirtualAddress(0, 0, 0)

    int page = 0;
    int offset = 0b111111;
    for(int i = 0; i < address.size(); ++i){
        if(i < 10){
            if(address[i] == '1'){
                page += pow(2,9-i);
            }
        }
    }

    return VirtualAddress(process_id, page, offset);


}


string VirtualAddress::to_string() const {
    // TODO: implement me
    //return "";

    return bitset<ADDRESS_BITS>(this->page).to_string();
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
    // TODO: implement me
    //return out;

    return (out << "PID " << address.process_id << " @ " << address.to_string() << " [page: " << address.page << "; offset: " << address.offset << "]" );
}
