#include "awtk.h"
#include "spine2d_register.h"

static ret_t on_clone(void* ctx, event_t* e) {
  widget_t* spine = widget_lookup(WIDGET(ctx), "spine2d", TRUE);
  widget_t* spine_new = widget_clone(spine, spine->parent);

  widget_move(spine_new, 10, 10);
  widget_set_name(spine_new, "spine_new");

  return RET_OK;
}

static ret_t on_close(void* ctx, event_t* e) {
  tk_quit();

  return RET_OK;
}

static ret_t on_anim_start(void* ctx, event_t* e) {
  widget_animator_event_t* evt = widget_animator_event_cast(e);
  widget_animator_t* animator = (widget_animator_t*)evt->animator;
  log_debug("on_anim_start: %s\n", animator->name);

  return RET_OK;
}

static ret_t on_anim_once(void* ctx, event_t* e) {
  widget_animator_event_t* evt = widget_animator_event_cast(e);
  widget_animator_t* animator = (widget_animator_t*)evt->animator;
  log_debug("on_anim_once: %s\n", animator->name);

  return RET_OK;
}

static ret_t on_anim_end(void* ctx, event_t* e) {
  widget_animator_event_t* evt = widget_animator_event_cast(e);
  widget_animator_t* animator = (widget_animator_t*)evt->animator;
  log_debug("on_anim_end: %s\n", animator->name);

  return RET_OK;
}

/**
 * 初始化
 */
ret_t application_init(void) {
  spine2d_register();

  widget_t* win = window_open("main");
  widget_child_on(win, "clone", EVT_CLICK, on_clone, win); 
  widget_child_on(win, "close", EVT_CLICK, on_close, win); 

  widget_child_on(win, "spine2d", EVT_ANIM_START, on_anim_start, win); 
  widget_child_on(win, "spine2d", EVT_ANIM_END, on_anim_end, win); 
  widget_child_on(win, "spine2d", EVT_ANIM_ONCE, on_anim_once, win); 

  return RET_OK;
}

/**
 * 退出
 */
ret_t application_exit(void) {
  log_debug("application_exit\n");
  return RET_OK;
}
