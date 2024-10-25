#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main() {
    // test (1) køen skal være tom
    { 
    queue q;
    initialize (&q);
    assert(empty(&q));
    }

    {   // test (2) enqueue og dequeue hvor x = y og køen skal være det samme som før udførelse
        queue q;
        initialize (&q);

        int x = 10;
        enqueue(&q,x);

        int y = dequeue(&q);

        assert(y == x);
        assert(empty(&q)); // køen skal være tom efter udførelse fordi det var den også inden udførelse
    }

    {
        // test (3) flere enqueue og dequeue hvor x = y og køen skal være det samme som før udførelse
        queue q;
        initialize (&q);

        int x0 = 20;
        int x1 = 30;
        enqueue(&q,x0);
        enqueue(&q,x1);

        int y0 = dequeue(&q);
        int y1 = dequeue(&q);

        assert(y0 == x0);
        assert(y1 == x1);
        assert(empty(&q)); // køen skal være tom efter udførelse fordi det var den også inden udførelse
    }
    return 0;
}