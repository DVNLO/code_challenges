#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct toggle_switch
{
    bool is_enabled;
    void (*enable_handler)(struct toggle_switch const * const);
    void (*disable_handler)(struct toggle_switch const * const);
} toggle_switch_t;

toggle_switch_t
toggle_switch_construct(bool const is_enabled,
        void (*enable_handler)(toggle_switch_t const * const),
        void (*disable_handler)(toggle_switch_t const * const))
{
    toggle_switch_t ret;
    ret.is_enabled = is_enabled;
    ret.enable_handler = enable_handler;
    ret.disable_handler = disable_handler;
    return ret;
}

bool
toggle_switch_is_enabled(toggle_switch_t const * const toggle_switch)
{
    return toggle_switch->is_enabled;
}

void
toggle_switch_enable(toggle_switch_t * const toggle_switch)
{
    // pass initial switch state to handler
    toggle_switch->enable_handler(toggle_switch);
    toggle_switch->is_enabled = true;
}

bool
toggle_switch_is_disabled(toggle_switch_t const * const toggle_switch)
{
    return !toggle_switch->is_enabled;
}

void
toggle_switch_disable(toggle_switch_t * const toggle_switch)
{
    // pass initial switch state to handler
    toggle_switch->disable_handler(toggle_switch);
    toggle_switch->is_enabled = false;
}

void enabled(toggle_switch_t const * const toggle_switch)
{
    if(toggle_switch_is_disabled(toggle_switch)) // rising edge
    {
        puts("toggle switch enabled");
    }
    else
    {
        puts("toggle switch re-enabled");
    }
}

void disabled(toggle_switch_t const * const toggle_switch)
{
    if(toggle_switch_is_enabled(toggle_switch)) // rising edge
    {
        puts("toggle switch disabled");
    }
    else
    {
        puts("toggle switch re-disabled");
    }
}

int main()
{
    toggle_switch_t s = toggle_switch_construct(false, enabled, disabled);
    assert(!s.is_enabled);
    assert(s.enable_handler == enabled);
    assert(s.disable_handler == disabled);

    toggle_switch_enable(&s);
    assert(toggle_switch_is_enabled(&s));
    assert(!toggle_switch_is_disabled(&s));

    toggle_switch_disable(&s);
    assert(!toggle_switch_is_enabled(&s));
    assert(toggle_switch_is_disabled(&s));

    toggle_switch_enable(&s);
    assert(toggle_switch_is_enabled(&s));
    assert(!toggle_switch_is_disabled(&s));

    toggle_switch_enable(&s);
    assert(toggle_switch_is_enabled(&s));
    assert(!toggle_switch_is_disabled(&s));

    toggle_switch_disable(&s);
    assert(!toggle_switch_is_enabled(&s));
    assert(toggle_switch_is_disabled(&s));

    toggle_switch_disable(&s);
    assert(!toggle_switch_is_enabled(&s));
    assert(toggle_switch_is_disabled(&s));

    return EXIT_SUCCESS;
}
