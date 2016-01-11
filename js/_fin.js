/* Implement customer javascript here */

(function ($, Drupal) {

    Drupal.behaviors.fin = {
        attach: function(context, settings) {
            $(window).scroll(function() {
                reset_top_bar_offset();
            });
            $(".navbar-tab").on("click", function(){
                setTimeout(reset_top_bar_offset, 10);
            });
            // For the product-nav-wrapper, set the data properties correctly
            $('.product-nav-item').each(function() {
                var arrival = $(this).attr("href");
                $(this).closest('dd').attr("data-magellan-arrival", arrival.replace("#", ""));
            });

            //sometimes the page is shorter than the off canvas moderation, so set a min height based on whatever is in the offcanvas 
            var offcanvasheight = 0; $(".left-off-canvas-menu").children().each(function(){ offcanvasheight += $(this).outerHeight(); });
             $('.off-canvas-wrap, .left-off-canvas-menu').css('min-height', offcanvasheight + 'px');

             //make the locations page have better transitions when it takes forever to load
            $('#views-exposed-form-location-finder-panel-pane-1').ajaxStart(function(){
               $('#edit-field-geofield-distance-origin, #edit-field-has-claims-adjuster-value').fadeTo(300, 0.3);
            });
            $('#views-exposed-form-location-finder-panel-pane-1').ajaxSuccess(function(){
               $('#edit-field-geofield-distance-origin, #edit-field-has-claims-adjuster-value').fadeTo(300, 1.0);
            });

              $('.view-location-finder').ajaxSuccess(function(){
               $('.views-row').fadeTo(300, 1.0);
            });
                $('.view-location-finder').ajaxStart(function(){
               $('.views-row').fadeTo(300, 0.3);
            });
        // locations page views gets all weird with its positioning of elements and doesnt work with our design. meh, close enough
            $('.view-footer').appendTo('.view-filters');

            // Custom logic for share button
            $(".contest-share-submit").on("click", function(e) {
                e.stopImmediatePropagation();
                // Count how many entries there are
                var entries = $(this).parent().find("input:checked").length;
                // If they checked any social media platforms, display a popup
                if (entries > 0) {
                    // text formatting
                    if (entries === 1) {
                        entries += " entry";
                    }
                    else {
                        entries += " entries";
                    }
                    $("#modalTitle").html("Thanks for sharing! You now have " + entries + " in the contest.");
                    $("#contestModal").foundation("reveal", "open");
                }
            });
        }
    };

    function reset_top_bar_offset() {
        // Check to see if the topbar is fixed
        var topbar = $(".sticky");
        var productbar = $(".product-nav-wrapper");
        if (topbar.hasClass("fixed")) {
            // Get the height of the navbar and apply it to the top-bar element
            var offset = $("#navbar-administration").children(":visible:last").outerHeight();
            // The navbar also may not exist
            if (offset) {
                topbar.css("top", offset);
            }
            else {
                offset = 0;
            }
            // The product bar will need to float below everything
            // Get the height of the topbar and apply it to the top-bar element
            var topbar_offset = topbar.outerHeight() + offset;
            // The navbar also may not exist
            if (topbar_offset) {
                productbar.css("margin-top", topbar_offset);
                // The anchors on the product page need to be readjusted as our floating elements change.
                $(".product-list .views-field-field-short-title a").each(function() {
                    $(this).css("top", -1 * topbar_offset);
                });
            }
        }
        else {
            productbar.css("margin-top", 0);
            topbar.css("top", 0);
        }
        // Finally check if product bar is no longer fixed, which only happens if the navbar is on screen
        if (!productbar.hasClass("fixed")) {
            productbar.css("margin-top", 0);
        }
    }


   //janrain writes directly to the dom element with !imporant so we cannot overrride there styles, thus we remove them and import our own (on window load because it loads late in the dom)
     $(window).load(function() {
       $(".janrainContent, #janrainAuthReturnExperience, .janrainHeader, #janrainProviderPages").removeAttr( "style" );
       });

     //add a wrapper to the iframe embed so that we can responsively target it. 
     $(document).ready(function(){
        jQuery('iframe').filter(function(){
         return this.src.match(/(youtube\.com|youtu\.be)/i);
        }).wrap("<div class='youtube-embed-container'></div>");

        });



})(jQuery, Drupal);