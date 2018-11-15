# $FreeBSD$

PORTNAME=	cliqz
DISTVERSION=	1.22.3
CATEGORIES=	www

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Web browser based on the browser portion of Mozilla

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nspr>=4.19:devel/nspr \
		nss>=3.39:security/nss \
		icu>=59.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=1.8.8:print/harfbuzz \
		graphite2>=1.3.12:graphics/graphite2 \
		png>=1.6.34:graphics/png \
		libvorbis>=1.3.6,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio \
		sqlite3>=3.24.0:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		llvm${LLVM_DEFAULT}>=0:devel/llvm${LLVM_DEFAULT} \
		rust>=1.28:lang/rust \
		rust-cbindgen>=0.6.2:devel/rust-cbindgen \
		autoconf-2.13:devel/autoconf213 \
		bash:shells/bash \
		wget:ftp/wget \
		yasm:devel/yasm \
		${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt \
		zip:archivers/zip

USES=		tar:xz gmake pkgconfig gnome python
USE_GNOME=	gconf2 gtk20 gtk30

LLVM_DEFAULT?=	70

USE_GITHUB=	yes
GH_ACCOUNT=	cliqz-oss
GH_PROJECT=	browser-f

USE_LDCONFIG=	yes

MAKE_ENV+=	LLVM_CONFIG=llvm-config${LLVM_DEFAULT}
MAKE_ENV+=	CQZ_RELEASE_CHANNEL=release

CLIQZ_ICON=		${PORTNAME}.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/${PORTNAME}/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

post-patch:
	@${CP} ${MOZ_DESKTOP} ${CLIQZ_DESKTOP}
	@${REINPLACE_CMD} -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/${PORTNAME}/g' \
		-e '/Icon=${PORTNAME}/ s/${PORTNAME}/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		${CLIQZ_DESKTOP}
do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/obj/dist/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}

post-install:
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/${PORTNAME}-bin ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	@${CP} ${CLIQZ_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include <bsd.port.mk>
