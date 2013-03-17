/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of MethodMaker.xs. Do not edit this file, edit MethodMaker.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "MethodMaker.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* inspired/stolen from Clone::Closure, to keep in sync with 5.13.3+ */
#ifndef CvGV_set
#define CvGV_set(cv,gv) CvGV(cv) = (gv)
#endif

#line 20 "MethodMaker.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 72 "MethodMaker.c"

XS(XS_Class__MethodMaker_set_sub_name); /* prototype to pass -Wmissing-prototypes */
XS(XS_Class__MethodMaker_set_sub_name)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 4)
       croak_xs_usage(cv,  "sub, pname, subname, stashname");
    {
	int	RETVAL;
	dXSTARG;
	SV *	sub = ST(0);
	char *	pname = (char *)SvPV_nolen(ST(1));
	char *	subname = (char *)SvPV_nolen(ST(2));
	char *	stashname = (char *)SvPV_nolen(ST(3));
#line 17 "MethodMaker.xs"
    if (!SvTRUE(ST(0)) || !SvTRUE(ST(1)) || !SvTRUE(ST(2)) || !SvTRUE(ST(3)))
      XSRETURN_UNDEF;
#line 94 "MethodMaker.c"
#line 20 "MethodMaker.xs"
    CvGV_set((CV*)SvRV(sub), gv_fetchpv(stashname, TRUE, SVt_PV));
    GvSTASH(CvGV((GV*)SvRV(sub))) = gv_stashpv(pname, 1);
#ifdef gv_name_set
    gv_name_set(CvGV((GV*)SvRV(sub)), subname, strlen(subname), GV_NOTQUAL);
#else
    GvNAME(CvGV((GV*)SvRV(sub))) = savepv(subname);
    GvNAMELEN(CvGV((GV*)SvRV(sub))) = strlen(subname);
#endif
    RETVAL = 1;
#line 105 "MethodMaker.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Class__MethodMaker); /* prototype to pass -Wmissing-prototypes */
XS(boot_Class__MethodMaker)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK ;

        (void)newXSproto_portable("Class::MethodMaker::set_sub_name", XS_Class__MethodMaker_set_sub_name, file, "$$$$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

