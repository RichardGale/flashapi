#if !defined(FLEX11_6_FLASH_ACCESSIBILITY_ISEARCHABLETEXT_AS)
#define FLEX11_6_FLASH_ACCESSIBILITY_ISEARCHABLETEXT_AS
#if defined(__cplusplus)


/**
 * The ISearchableText interface can be implemented by objects that
 * contain text which should be searchable on the web.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 */

namespace flash
{
    namespace accessibility
    {
        class ISearchableText
        {
            /**
             * Gets the search text from a component implementing ISearchableText.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             */
            virtual std::string searchText() = 0;
        };
    }
}

#endif // FLEX11_6_FLASH_ACCESSIBILITY_ISEARCHABLETEXT_AS
#endif // __cplusplus

