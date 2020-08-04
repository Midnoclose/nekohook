
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <unordered_map>

namespace nekohook {

template<typename T, typename ID_T, template<typename, typename> typename UMap = std::unordered_map>
class IdTree {
public:
    auto begin() { return this->root.begin(); }
    auto end() { return this->root.end(); }
    template<class I, class... TT>
    auto emplace(I begin, I end, TT... in) {
        typename NodeMap::iterator cur = &this->root;
        for (auto i = begin; i != end; i++)
            cur = *cur.children[i];
        (*cur).data.push_back(v);
    }
    template<class I>
    auto find(I begin, I end) {
        typename NodeMap::iterator cur = &this->root;
        for (auto i = begin; i != end; i++) { 
            auto find = cur->find(*i);
            if (find == cur->end())
                return end;
            cur = find;
        }
        return cur; 
    }
private:
    struct Node;
    using NodeMap = UMap<ID_T, Node*>;
    struct Node {
        Node(Node* _parent) : parent(_parent) {}
        template<class TT...>
        Node(Node* _parent, TT... in) : parent(_parent), data(in...) {}
        Node* parent;
        NodeMap children;
        T data;
    };
    Node root = nullptr;
};

}
