#pragma once

#include <container/seadPtrArray.h>

namespace al {

class Graph {
public:
    class Edge;

    class Vertex {
    public:
        inline Vertex(s32 size, s32 index) : mIndex(index) { mEdges.allocBuffer(size, nullptr); }

        const sead::PtrArray<Edge>& getEdges() const { return mEdges; }

        s32 getIndex() const { return mIndex; }

        void addEdge(Edge* edge) { mEdges.pushBack(edge); }

        void tryAddEdge(Edge* edge) {
            for (s32 i = 0; i < mEdges.size(); i++)
                if (mEdges[i] == edge)
                    return;
            addEdge(edge);
        }

    public:
        sead::PtrArray<Edge> mEdges;
        s32 mIndex;
    };

    static_assert(sizeof(Vertex) == 0x18);

    class Edge {
    public:
        Edge(Vertex* vertex1, Vertex* vertex2, f32 weight)
            : mVertex1(vertex1), mVertex2(vertex2), mWeight(weight) {}

        virtual f32 getWeight() const { return mWeight; }

        Vertex* getVertex1() const { return mVertex1; }

        Vertex* getVertex2() const { return mVertex2; }

    public:
        Vertex* mVertex1;
        Vertex* mVertex2;
        f32 mWeight;
    };

    static_assert(sizeof(Edge) == 0x20);

    Graph(s32 vertices_size, s32 edges_size);
    void appendVertex(s32 size);
    void appendVertex(Vertex* vertex);
    void removeVertex(const Vertex* vertex);
    void removeEdge(const Edge* edge);
    Edge* tryFindEdge(s32 index_vertex1, s32 index_vertex2) const;
    void appendEdge(Edge* edge);
    bool tryAppendEdge(Edge* edge);
    void appendEdge(s32 index_vertex1, s32 index_vertex2, f32 weight);
    bool tryAppendEdge(s32 index_vertex1, s32 index_vertex2, f32 weight);

public:
    sead::PtrArray<Vertex> mVertices;
    sead::PtrArray<Edge> mEdges;
};

static_assert(sizeof(Graph) == 0x20);

}  // namespace al
