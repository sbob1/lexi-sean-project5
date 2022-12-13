/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;


size_t PageTable::get_present_page_count() const {
    size_t num_pages = 0;
    for(Row current: rows) {
        if(current.present) {
            num_pages++;
        }
    }
    return num_pages++;
}


size_t PageTable::get_oldest_page() const {
    size_t oldest = 0;
    size_t page_index = 0;
    size_t max_age = 0;
    for(Row current: rows) {
        if(current.present) {
            if(max_age == 0 || max_age > current.loaded_at) {
                if(current.loaded_at != -1) {
                    max_age = current.loaded_at;
                    oldest = page_index;
                }
            }
        }
        page_index++;
    }

    return oldest;
}


size_t PageTable::get_least_recently_used_page() const {
    size_t recent = 0;
    size_t page_index = 0;
    size_t min_age = 0;
    for(Row current: rows) {
        if(current.present) {
            if(min_age == 0 || min_age > current.last_accessed_at) {
                if(current.last_accessed_at != -1) {
                    min_age = current.last_accessed_at;
                    recent = page_index;
                }
            }
        }
        page_index++;
    }

    return recent;
}
