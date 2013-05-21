#if !defined(FLEX11_6_FLASH_PROFILER_PACKAGE_AS_AS)
#define FLEX11_6_FLASH_PROFILER_PACKAGE_AS_AS
#if defined(__cplusplus)


public:
void     profile(bool on);
/**
 * Shows or hides redraw regions. Enables the debugger version of Flash   Player to outline
 * the regions of the screen that are being redrawn (that is regions that are being
 * updated).
 * @param   on  Specifies whether to show or hide
 *   redraw regions. When set to true, the redraw rectangles are
 *   shown. When set to false, the redraw rectangles are hidden.
 * @param   color   Sets the color of the rectangles. If you do not specify this parameter,
 *   0xFF0000 is used.
 * @langversion 3.0
 * @playerversion   Flash 9
 */
public:
void     showRedrawRegions(bool on, unsigned int color=16711680);
#endif // FLEX11_6_FLASH_PROFILER_PACKAGE_AS_AS
#endif // __cplusplus

