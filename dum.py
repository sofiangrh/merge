# -*- coding: utf-8 -*-
from django.views import generic
from .models import Person


class QuerySetMixin(object):

    model = Person


class DetailView(QuerySetMixin, generic.DetailView):

    pass


class ListView(QuerySetMixin, generic.ListView):

    pass
