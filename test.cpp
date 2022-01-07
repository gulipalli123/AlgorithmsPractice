// Type your code here, or load an example.
/*#include <map>
#include <limits>
#include <iostream>

template<typename K, typename V>
class interval_map {
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const& val) {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        // INSERT YOUR SOLUTION HERE
        if (!(keyBegin < keyEnd))
            return;
        auto it_key_begin = m_map.upper_bound(keyBegin);
        auto it_key_end = m_map.upper_bound(keyEnd);

        it_key_begin--;
        it_key_end--;
        std::pair<K, V> current = *it_key_begin;
        std::pair<K, V> next = *it_key_end;
        if (std::next(it_key_end) == m_map.end())
        {
            if (it_key_end->second == std::numeric_limits<V>::max() && it_key_end->first < keyEnd
                && it_key_end->first > keyBegin)
            {
                auto nextNode = m_map.extract(it_key_end->first);
                nextNode.key() = keyEnd;
                m_map.insert(std::move(nextNode));
            }
            else
            {
                m_map.insert(it_key_end, std::make_pair(keyEnd, std::numeric_limits<V>::max()));
            }

        }
        else if (std::next(it_key_end)->second == std::numeric_limits<V>::max())
        {
            auto nextNode = m_map.extract(std::next(it_key_end)->first);
            nextNode.key() = keyEnd;
            m_map.insert(std::move(nextNode));
        }
        if (!(std::numeric_limits<K>::lowest() < current.first))
        {
            m_map.insert(it_key_begin, std::make_pair(keyBegin, val));
            return;
        }

        if (!(current.first < keyBegin))
        {
            if (std::prev(it_key_begin)->second == val)
                m_map.erase(current.first);
            else if (std::next(it_key_begin)->second == val)
            {
                m_map.erase(std::next(it_key_begin)->first);
                m_map[current.first] = val;
            }
            else
                m_map[std::next(it_key_begin)->first] = val;

        }
        else
        {
            if (!(current.second == val) && !(next.second == val))
            {
                m_map.insert(it_key_begin, std::make_pair(keyBegin, val));
                return;
            }
        }
        if (it_key_end->second == val)
        {
            std::pair<K, V> next = *(std::next(it_key_end));
            m_map.erase(std::next(it_key_begin), std::next(it_key_end));
            auto nextNode = m_map.extract(next.first);
            nextNode.key() = keyEnd;
            m_map.insert(std::move(nextNode));
        }
        else
        {
            if (std::next(it_key_begin) != it_key_end)
            {
                m_map.erase(std::next(it_key_begin), it_key_end);
            }

        }

    }

    // look-up of the value associated with key
    V const& operator[](K const& key) const {
        return (--m_map.upper_bound(key))->second;
    }
    void printMap()
    {
        for (auto it = m_map.begin(); it != m_map.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
};
int main()
{
    interval_map<int, char>my_map('A');
    my_map.assign(0, 5, 'B');
    my_map.assign(2, 6, 'C');
    my_map.assign(8, 12, 'D');
    my_map.assign(2, 6, 'B');
    my_map.assign(9, 11, 'C');
    my_map.printMap();

}*/