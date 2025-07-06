; ModuleID = 'core.cpp'
source_filename = "core.cpp"
target datalayout = "e-m:x-p:32:32-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:32-n8:16:32-a:0:32-S32"
target triple = "i686-w64-windows-gnu"

%class.Int = type { i32 }

$_ZN3IntC2Ei = comdat any

; Function Attrs: mustprogress noinline norecurse optnone
define dso_local noundef i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca %class.Int, align 4
  store i32 0, ptr %1, align 4
  call x86_thiscallcc void @_ZN3IntC2Ei(ptr noundef nonnull align 4 dereferenceable(4) %2, i32 noundef 42)
  ret i32 0
}

; Function Attrs: mustprogress noinline nounwind optnone
define linkonce_odr dso_local x86_thiscallcc void @_ZN3IntC2Ei(ptr noundef nonnull align 4 dereferenceable(4) %0, i32 noundef %1) unnamed_addr #1 comdat align 2 {
  %3 = alloca ptr, align 4
  %4 = alloca i32, align 4
  store ptr %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %5 = load ptr, ptr %3, align 4
  %6 = load i32, ptr %4, align 4
  %7 = getelementptr inbounds %class.Int, ptr %5, i32 0, i32 0
  store i32 %6, ptr %7, align 4
  ret void
}

attributes #0 = { mustprogress noinline norecurse optnone "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress noinline nounwind optnone "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"NumRegisterParameters", i32 0}
!1 = !{i32 1, !"wchar_size", i32 2}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"(built by Brecht Sanders, r2) clang version 18.1.7"}
