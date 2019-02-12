#include <mruby.h>
#include <mruby/string.h>
#include <stdio.h>

void tes(mrb_state *mrb);

// CRubyExtension.c_method
// #0  mrb_c_method (mrb=0x56033b5812a0, self=...) at /home/wsh/qc/mruby/examples/mrbgems/c_and_ruby_extension_example/src/example.c:9
// #1  0x000056033b0fdda5 in mrb_vm_exec (mrb=0x56033b5812a0, proc=0x56033b5f6060, pc=0x56033b60bd37 "7\001g") at /home/wsh/qc/mruby/src/vm.c:1478
// #2  0x000056033b0fa6d0 in mrb_vm_run (mrb=0x56033b5812a0, proc=0x56033b5f6060, self=..., stack_keep=0) at /home/wsh/qc/mruby/src/vm.c:945
// #3  0x000056033b10c7b6 in mrb_top_run (mrb=0x56033b5812a0, proc=0x56033b5f6060, self=..., stack_keep=0) at /home/wsh/qc/mruby/src/vm.c:2875
// #4  0x000056033b125725 in mrb_load_exec (mrb=0x56033b5812a0, p=0x56033b600040, c=0x56033b5fff80) at mrbgems/mruby-compiler/core/parse.y:6522
// #5  0x000056033b125839 in mrb_load_nstring_cxt (mrb=0x56033b5812a0, s=0x56033b5fff40 "CRubyExtension.c_method", len=23, c=0x56033b5fff80) at mrbgems/mruby-compiler/core/parse.y:6544
// #6  0x000056033b1258af in mrb_load_string_cxt (mrb=0x56033b5812a0, s=0x56033b5fff40 "CRubyExtension.c_method", c=0x56033b5fff80) at mrbgems/mruby-compiler/core/parse.y:6556
// #7  0x000056033b0ce3f1 in main (argc=4, argv=0x7ffc308d5e58) at /home/wsh/qc/mruby/mrbgems/mruby-bin-mruby/tools/mruby/mruby.c:346
static mrb_value
mrb_c_method(mrb_state *mrb, mrb_value self)
{
  mrb_value self_str = mrb_str_to_str(mrb, self);

  printf("%s: A C Extension\n", mrb_str_to_cstr(mrb, self_str));
  tes(mrb);

  return self;
}

// called at startup
// #0  mrb_c_and_ruby_extension_example_gem_init (mrb=0x560b61bd42a0) at /home/wsh/qc/mruby/examples/mrbgems/c_and_ruby_extension_example/src/example.c:16
// #1  0x0000560b611a1f2d in GENERATED_TMP_mrb_c_and_ruby_extension_example_gem_init (mrb=0x560b61bd42a0) at /home/wsh/qc/mruby/build/host/mrbgems/c_and_ruby_extension_example/gem_init.c:61
// #2  0x0000560b61197f8c in mrb_init_mrbgems (mrb=0x560b61bd42a0) at /home/wsh/qc/mruby/build/host/mrbgems/gem_init.c:134
// #3  0x0000560b6117ca9f in init_mrbgems (mrb=0x560b61bd42a0, opaque=0x0) at /home/wsh/qc/mruby/src/state.c:83
// #4  0x0000560b6114e4c4 in mrb_core_init_protect (mrb=0x560b61bd42a0, body=0x560b6117ca7f <init_mrbgems>, opaque=0x0) at /home/wsh/qc/mruby/src/error.c:569
// #5  0x0000560b6117caf3 in mrb_open_allocf (f=0x560b6117ca0d <mrb_default_allocf>, ud=0x0) at /home/wsh/qc/mruby/src/state.c:96
// #6  0x0000560b6117ca75 in mrb_open () at /home/wsh/qc/mruby/src/state.c:75
// #7  0x0000560b6113de89 in main (argc=4, argv=0x7fff3b06ae68) at /home/wsh/qc/mruby/mrbgems/mruby-bin-mruby/tools/mruby/mruby.c:260
void
mrb_c_and_ruby_extension_example_gem_init(mrb_state* mrb) {
  struct RClass *class_cextension = mrb_define_module(mrb, "CRubyExtension");
  mrb_define_class_method(mrb, class_cextension, "c_method", mrb_c_method, MRB_ARGS_NONE());
}

// called at exit
// #0  mrb_c_and_ruby_extension_example_gem_final (mrb=0x55c067bb22a0) at /home/wsh/qc/mruby/examples/mrbgems/c_and_ruby_extension_example/src/example.c:34
// #1  0x000055c067589fda in GENERATED_TMP_mrb_c_and_ruby_extension_example_gem_final (mrb=0x55c067bb22a0) at /home/wsh/qc/mruby/build/host/mrbgems/c_and_ruby_extension_example/gem_init.c:75
// #2  0x000055c06757ff25 in mrb_final_mrbgems (mrb=0x55c067bb22a0) at /home/wsh/qc/mruby/build/host/mrbgems/gem_init.c:123
// #3  0x000055c067564ed3 in mrb_close (mrb=0x55c067bb22a0) at /home/wsh/qc/mruby/src/state.c:185
// #4  0x000055c067525e51 in cleanup (mrb=0x55c067bb22a0, args=0x7ffeda727130) at /home/wsh/qc/mruby/mrbgems/mruby-bin-mruby/tools/mruby/mruby.c:252
// #5  0x000055c067526489 in main (argc=4, argv=0x7ffeda727288) at /home/wsh/qc/mruby/mrbgems/mruby-bin-mruby/tools/mruby/mruby.c:362
void
mrb_c_and_ruby_extension_example_gem_final(mrb_state* mrb) {
  /* finalizer */
  asm("nop");
}
