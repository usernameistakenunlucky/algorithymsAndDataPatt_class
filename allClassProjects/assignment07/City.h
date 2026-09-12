#pragma once
#include <Vector.h>
#include <MSTGraph.h>
#include <MSTGraphK.h>
#include "House.h"

class City
{
private:
    Vector<House> _houses;
    MSTGraph<House, float> _housesGraph;
    MSTGraphK<House, float> _houseEdgesGraph;

public:
    City() {}

    void AddHouse(const std::string& name, const Vector2& pos)
    {
        for (const auto& house : _houses)
        {
            if (house.name == name)
            {
                std::cout << "Error: house already exists in _houses.\n";
                return;
            }
        }
        _houses.PushBack(House{ name, pos });
    }

    void ConnectAllHouses()
    {
        for (std::size_t i = 0; i < _houses.Size(); ++i)
        {
            _housesGraph.AddItem(&_houses[i]);
            _houseEdgesGraph.AddItem(&_houses[i]);
        }

        const float maxLinkDistance = 75.0f;

        for (std::size_t i = 0; i < _houses.Size(); ++i)
        {
            for (std::size_t j = i + 1; j < _houses.Size(); ++j)
            {
                float distanceX = _houses[i].position.x - _houses[j].position.x;
                float distanceY = _houses[i].position.y - _houses[j].position.y;
                float distance = std::sqrt((distanceX * distanceX) + (distanceY * distanceY));

                if (distance <= maxLinkDistance)
                {
                    _housesGraph.AddLink(i, j, distance);
                    _houseEdgesGraph.AddEdge(i, j, distance);
                }
            }
        }
    }

    float GetTotalRoadDistancePrim()
    {
        Vector<const House*> mst;
        Vector<const House*> links;
        float totalWeight = 0.0f;

        _housesGraph.ObtainMST(0, mst, links, totalWeight);

        return totalWeight;
    }

    float GetTotalRoadDistanceKruskal()
    {
        Vector<const House*> mst;
        Vector<const House*> links;
        float totalWeight = 0.0f;

        _houseEdgesGraph.ObtainMST(mst, links, totalWeight);

        return totalWeight;
    }

    void PrintMST()
    {
        Vector<const House*> mst;
        Vector<const House*> links;
        float totalWeight = 0.0f;

        _housesGraph.ObtainMST(0, mst, links, totalWeight);

        for (std::size_t i = 0; i < _houses.Size(); ++i)
        {
            if (links[i] != nullptr)
            {
                std::cout << links[i]->name << " -- " << _houses[i].name << "\n";
            }
        }
    }

    void PrintKMST()
    {
        Vector<const House*> mst;
        Vector<const House*> links;
        float totalWeight = 0.0f;

        _houseEdgesGraph.ObtainMST(mst, links, totalWeight);

        for (std::size_t i = 0; i < _houses.Size(); ++i)
        {
            if (links[i] != nullptr)
            {
                std::cout << links[i]->name << " -- " << _houses[i].name << "\n";
            }
        }
    }

};