--- mozilla-release/nsprpub/pr/src/pthreads/ptsynch.c.orig	2018-11-12 14:16:18 UTC
+++ mozilla-release/nsprpub/pr/src/pthreads/ptsynch.c
@@ -911,7 +911,8 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphore(const char *
  * From the semctl(2) man page in glibc 2.0
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
-    || defined(FREEBSD) || defined(OPENBSD) || defined(BSDI) \
+    || (defined(FREEBSD) && __FreeBSD_version < 1200059) \
+    || defined(OPENBSD) || defined(BSDI) \
     || defined(DARWIN) || defined(SYMBIAN)
 /* union semun is defined by including <sys/sem.h> */
 #else
