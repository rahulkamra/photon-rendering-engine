#pragma once
#include <map>
#include <boost\none.hpp>
#include <boost\optional.hpp>

template<typename K, typename V>
class EMap 
{

private:
	std::map<K,V> map;
public:
	EMap()
	{

	}
	
	~EMap()
	{

	}

	void set(K key,V value)
	{
		map.insert(std::pair<K, V>(key, value));
	}


	boost::optional<V> get(K key)
	{
		std::map<K, V>::iterator  it = map.find(key);
		if (it != map.end())
		{
			return it->second;
		}
		else
			return boost::none;
	}
	


};

