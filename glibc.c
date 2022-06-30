#define _GNU_SOURCE

#include <stdio.h>
#include <sched.h>
#include <sys/mount.h>
#include <unistd.h>

#define e(n,f) if (-1 == (f)) {perror(n);return(1);}
#define SRC "/glibc"

int main(int argc, const char const *argv[]) {
  const char const *shell[] = { "/bin/sh", NULL };

  // Move glibc stuff in place
  e("unshare", unshare(CLONE_NEWNS));
  e("mount", mount(SRC "/usr", "/usr", NULL, MS_BIND, NULL));
  e("mount", mount(SRC "/var/db/xbps", "/var/db/xbps", NULL, MS_BIND, NULL));

  // drop the rights suid gave us
  e("setuid", setreuid(getuid(),getuid()));
  e("setgid", setregid(getgid(),getgid()));

  argv++;
  if (!argv[0]) argv = shell;
  e("execv", execvp(argv[0], argv));
}
