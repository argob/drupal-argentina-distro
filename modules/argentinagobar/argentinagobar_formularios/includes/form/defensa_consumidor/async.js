function modificacionesCSSPedidas() {
    jQuery("#edit-archivoscondicional-tiene-documentacion").click(function() {
        1 == jQuery("#edit-archivoscondicional-tiene-documentacion .btn.btn-default.active").find("input").val() ? jQuery("#claim_documentacion").hide() : jQuery("#claim_documentacion").show()
    }), jQuery("#agregarDocumento").length < 1 && jQuery("#doc9").after('<div style="margin-bottom: 20px;" class="btn btn-default disabled" id="agregarDocumento">+ Agregar documento</div> <div style="margin-bottom: 20px;" class="btn btn-danger disabled" id="quitarDocumento">- Quitar documento</div>'), jQuery('[id^="doc"]').find("input:file").change(function() {
        jQuery("#quitarDocumento").removeClass("disabled"), jQuery("#agregarDocumento").removeClass("disabled"), jQuery("#doc9").is(":visible") && jQuery("#agregarDocumento").addClass("disabled")
    }), jQuery("#agregarDocumento").unbind("click").click(function() {
        jQuery("#agregarDocumento").hasClass("disabled") || (jQuery("div[class*='form-item-documento']").parent().not(":visible").first().show(), jQuery("#doc9").is(":visible") && jQuery("#agregarDocumento").removeClass("disabled"), jQuery("#agregarDocumento").addClass("disabled"), jQuery("#quitarDocumento").removeClass("disabled"))
    }), jQuery("#quitarDocumento").unbind("click").click(function() {
        if (!jQuery("#quitarDocumento").hasClass("disabled"))
            for (i = 10; i >= 0; i--)
                if (jQuery("#doc" + i).is(":visible")) {
                    i > 0 && (jQuery("#doc" + i).hide(), jQuery("#agregarDocumento").removeClass("disabled")), jQuery("#doc" + i).find("input").val(""), 0 == i && 0 == jQuery("#doc" + i).find("input").val() && (jQuery("#quitarDocumento").addClass("disabled"), jQuery("#agregarDocumento").addClass("disabled"));
                    break
                }
    }), jQuery("#doc9").children().is(":visible") && jQuery("#agregarDocumento").addClass("disabled"), jQuery(".panel-heading:first").append(jQuery(".pane-argentinagobar-ciudadano-digital-completardatosmiargentina").html()), jQuery(".pane-argentinagobar-ciudadano-digital-completardatosmiargentina").hide(), jQuery("legend.panel-heading").attr({
        style: "padding-top:15px; padding-bottom:5px; border-top:1px solid #ccc; border-bottom:none;"
    }), jQuery("legend").removeClass("panel-heading"), jQuery("#agregarProveedor").length < 1 && jQuery("#prov4").after('<div style="margin-bottom: 20px;" class="btn btn-default" id="agregarProveedor">+ Agregar proveedor</div>'), jQuery("#agregarProveedor").unbind("click").click(function() {
        jQuery("div[id*='prov']").not(":visible").first().show(), jQuery("#prov4").is(":visible") && jQuery("#agregarProveedor").hide()
    }), jQuery("#prov4").children().is(":visible") && jQuery("#agregarProveedor").hide(), jQuery("#edit-reclamo-esusuario .form-required").remove()
}
jQuery(document).ready(function() {
    modificacionesCSSPedidas()
}), jQuery(document).ajaxComplete(function() {
    modificacionesCSSPedidas()
}), jQuery(function() {
    jQuery(".localidad").each(function() {
        jQuery(this).chained(jQuery(this).parent().find(".prov"))
    })
});