/*************************************************************************
    libportal, A Network Library
    Copyright (C) 2017  hepangda

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/
#include<portal/multiplexing.h>

using libportal::MultiplexEpoll;

MultiplexEpoll::MultiplexEpoll() {
    epoll_fd = epoll_create(100);   //TODO:Fix Magic Number
}

MultiplexEpoll::~MultiplexEpoll() {
    close(epoll_fd);                //TODO:Handle Error
}

int MultiplexEpoll::Add(int fd, unsigned int events, void *ptr) {
    epoll_data evt_data;
    evt_data.ptr = ptr;
    epoll_event this_event = { events, evt_data };

    return epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &this_event);
}

int MultiplexEpoll::Modify(int fd, unsigned int events, void *ptr) {
    epoll_data evt_data;
    evt_data.ptr = ptr;
    epoll_event this_event = { events, evt_data };

    return epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &this_event);
}

int MultiplexEpoll::Delete(int fd) {
    return epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
}

int MultiplexEpoll::Wait() {

}
//int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
int MultiplexEpoll::WaitUntil() {

}