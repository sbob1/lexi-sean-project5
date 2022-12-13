/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"

using namespace std;


Process* Process::read_from_input(std::istream& in) {
    // TODO
    //return nullptr;

    std::vector<Page*> pages;

    size_t bytes_num = 0;
    
    while(!in.eof()){
        Page* this_page = Page::read_from_input(in);

        pages.push_back(this_page);

        bytes_num += in.gcount();


    }

    Process* return_process = new Process(num_bytes, pages);

    return return_process;

}


size_t Process::size() const
{
    // TODO
    return this->num_bytes;
}


bool Process::is_valid_page(size_t index) const
{
    // TODO
    if(pages.size() > index){
        return true;
    }
    else{
    return false;
    }
}


size_t Process::get_rss() const
{
    // TODO
    return page_table.get_present_page_count();
}


double Process::get_fault_percent() const
{
    // TODO
    if (memory_accesses == 0) return 0;
    else return page_faults * 100.0 / memory_accesses;
}
