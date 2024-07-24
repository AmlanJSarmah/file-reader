#ifndef __READER__
#define __READER__

void get_data_from_file(char* path, char* buffer);
struct winsize get_editor_size();
void window_resize_signal_handle(int signum);

#endif