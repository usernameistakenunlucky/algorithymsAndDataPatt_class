#pragma once

#include "Vector.h"
#include "Global.h"

class DisjointSetUnion
{
public:
    DisjointSetUnion(std::size_t numNodes)
    {
        mParent.Resize(numNodes);
        mRank.Resize(numNodes, 0);
        for (std::size_t i = 0; i < numNodes; ++i)
        {
            mParent[i] = i;
        }
    }
    std::size_t FindParentIndex(std::size_t index)
    {
        if (mParent[index] != index)
        {
            mParent[index] = FindParentIndex(mParent[index]);
        }
        return mParent[index];
    }
    bool UniteEdges(int& from, int& to)
    {
        std::size_t rootFrom = FindParentIndex(from);
        std::size_t rootTo = FindParentIndex(to);
        if (rootFrom == rootTo)
        {
            // already in the same set
            return false;
        }
        if (mRank[rootFrom] < mRank[rootTo])
        {
            mParent[rootFrom] = rootTo;
            Global::Swap(from, to);
        }
        else if (mRank[rootFrom] > mRank[rootTo])
        {
            mParent[rootTo] = rootFrom;
        }
        else
        {
            mParent[rootTo] = rootFrom;
            ++mRank[rootFrom];
        }
        return true;
    }

private:
    Vector<int> mParent;
    Vector<int> mRank;
};

template<typename T, typename W = int>
class MSTGraphK
{
private:
    struct Edge
    {
        int from = -1;
        int to = -1;
        W weight;
    };
    struct Node
    {
        const T* data = nullptr;
        bool isAdded = false;
    };
public:
    MSTGraphK()
    {

    }
    ~MSTGraphK()
    {
        Terminate();
    }
    void AddItem(const T* data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        mNodes.PushBack(newNode);
    }
    void AddEdge(std::size_t from, std::size_t to, W weight)
    {
        Edge newEdge = { from, to, weight };
        mEdges.PushBack(newEdge);
    }
    void ObtainMST(Vector<const T*>& mst, Vector<const T*>& links, W& totalWeight)
    {
        Reset();
        std::size_t numNodes = mNodes.Size();
        Vector<Edge> processed;
        links.Resize(numNodes, nullptr);
        DisjointSetUnion dsu(numNodes);
        Global::IntroSort(mEdges.Begin(), mEdges.End(),
            [](const Edge& a, const Edge& b)
            {
                return a.weight < b.weight;
            });
        for (std::size_t i = 0; i < mEdges.Size(); ++i)
        {
            Edge& edge = mEdges[i];
            if (dsu.UniteEdges(edge.from, edge.to))
            {
                totalWeight += edge.weight;
                if (!mNodes[edge.from]->isAdded)
                {
                    mNodes[edge.from]->isAdded = true;
                    mst.PushBack(mNodes[edge.from]->data);
                }
                if (!mNodes[edge.to]->isAdded)
                {
                    mNodes[edge.to]->isAdded = true;
                    mst.PushBack(mNodes[edge.to]->data);
                }
                processed.PushBack(edge);
                if (processed.Size() == numNodes - 1)
                {
                    break;
                }
            }
        }
        for (std::size_t i = 0; i < processed.Size(); ++i)
        {
            Edge& edge = processed[i];
            links[edge.to] = mNodes[edge.from]->data;
        }
    }

    void Terminate()
    {
        for (std::size_t i = 0; i < mNodes.Size(); ++i)
        {
            delete mNodes[i];
            mNodes[i] = nullptr;
        }
        mNodes.Clear();
        mEdges.Clear();
    }
private:
    void Reset()
    {
        for (std::size_t i = 0; i < mNodes.Size(); ++i)
        {
            mNodes[i]->isAdded = false;
        }
    }
    Vector<Node*> mNodes;
    Vector<Edge> mEdges;
};