function eduAjax(url, data, successCallback) {
    $.post(url, data, function (json) {
        if (json["error"]) {
            alert(json["error"]);
        } else if (json["redirect"]) {
            Codeforces.redirect(json["redirect"]);
        } else if (json["success"] === "true") {
            if (successCallback) {
                successCallback(json);
            } else {
                Codeforces.reload();
            }
        }
    }, "json");
}
